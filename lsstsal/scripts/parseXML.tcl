#!/usr/bin/env tclsh

proc parseXMLtoidl { fname } { 
global IDLRESERVED SAL_WORK_DIR SAL_DIR CMDS CMD_ALIASES EVTS EVENT_ALIASES
global TLMS TLM_ALIASES EVENT_ENUM EVENT_ENUMS UNITS ENUM_DONE
   set fin [open $fname r]
   set fout ""
   set ctype ""
   set subsys [lindex [split [file tail $fname] _] 0]
   set tname none
   set itemid none
   set intopic 0
   while { [gets $fin rec] > -1 } {
      set st [string trim $rec]
      if { [string range $st 0 3] == "<!--" } {
         if { [string range [string reverse $st] 0 2] != ">--" } {
            set skip 1
            while { $skip } {
               gets $fin rec
               set st [string trim $rec]
               if { [string range [string reverse $st] 0 2] == ">--" } {
                  set skip 0
                  gets $fin rec
                  set st [string trim $rec]
                  if { [string range $st 0 3] == "<!--" } {set skip 1}
               }
            }
         }
      }
      set tag   [lindex [split $rec "<>"] 1]
      set value [lindex [split $rec "<>"] 2]
      if { $tag == "SALTelemetry" }    {set ctype "telemetry" ; set intopic 1}
      if { $tag == "SALCommand" }      {
          set ctype "command" ; set intopic 1 ; set alias ""
          set device ""; set property ""; set action "" ; set vvalue ""
      }
      if { $tag == "SALEvent" }        {set ctype "event" ; set intopic 1; set alias ""}
      if { $tag == "SALTelemetrySet" } {set ctype "telemetry"}
      if { $tag == "SALCommandSet" }   {set ctype "command"}
      if { $tag == "SALEventSet" }     {set ctype "event"}
      if { $tag == "Alias" }           {
          set alias $value
          if { $ctype == "command" } {set CMDS($subsys,$alias) $alias}
          if { $ctype == "event" }   {set EVTS($subsys,$alias) $alias}
      }
      if { $tag == "Device" }          {set device $value}
      if { $tag == "Property" }        {set property $value}
      if { $tag == "Action" }          {set action $value}
      if { $tag == "Value" }           {set vvalue $value}
      if { $tag == "Subsystem" }       {set subsys $value}
      if { $tag == "Enumeration" }     {
         if { $intopic } {
           lappend EVENT_ENUM($alias) "$item:$value"
           set EVENT_ENUMS($alias,$item) "$value"
         } else {
           lappend EVENT_ENUM([set subsys]_shared) "generic_shared:$value"
           set EVENT_ENUMS([set subsys]_shared,generic_shared) "$value"
         }
      }
      if { $tag == "/SALEvent" } {
         set intopic 0
         set shouldbe [join [lrange [split $tname _] 2 end] "_"]
         if { $alias != $shouldbe } {
             puts stdout "****************************************************************"
             puts stdout "****************************************************************"
             puts stdout "ERROR - Alias does not match EFDB_Topic declaration for $alias"
             puts stdout "****************************************************************"
             puts stdout "****************************************************************"
             exit
         }
         set EVTS($subsys,$alias) $alias
         set EVENT_ALIASES($subsys) [lappend EVENT_ALIASES($subsys) $alias]
         if { [info exists EVTS($subsys,$alias,plist)] } {
          if { [lsearch $EVTS($subsys,$alias,plist) priority] < 0 } {
            lappend EVTS($subsys,$alias,param) "long	priority"
            lappend EVTS($subsys,$alias,plist) priority
            puts $fout "	  long	priority;"
          }
         } else {
          lappend EVTS($subsys,$alias,param) "long	priority"
          lappend EVTS($subsys,$alias,plist) priority
          puts $fout "	  long	priority;"
         }
      }
      if { $tag == "/SALCommand" } {
         set intopic 0
         set shouldbe [join [lrange [split $tname _] 2 end] "_"]
         if { $alias != $shouldbe } {
             puts stdout "****************************************************************"
             puts stdout "****************************************************************"
             puts stdout "ERROR - Alias does not match EFDB_Topic declaration for $alias"
             puts stdout "****************************************************************"
             puts stdout "****************************************************************"
             exit
         }
         set CMDS($subsys,$alias) "$device $property $action $vvalue"
         set CMD_ALIASES($subsys) [lappend CMD_ALIASES($subsys) $alias]
         if { $itemid == 0 } {
            puts stdout "WARNING : Command $alias has no data fields , adding default state item"
            lappend CMDS($subsys,$alias,param) "boolean state"
            lappend CMDS($subsys,$alias,plist) state
            puts $fout "	  boolean	state;"
         }
      }
      if { $tag == "/SALTelemetry" } {
         set TLM_ALIASES($subsys) [lappend TLM_ALIASES($subsys) $alias]
         set intopic 0
      }
      if { $tag == "EFDB_Topic" } {
        if { $fout != "" } {
           puts $fout "\};"
           puts $fout "#pragma keylist $tname"
           close $fout
           if { $ctype == "telemetry" } {
             close $fsql
           }
        }
        set itemid 0
        if { [info exists topics($value)] } { 
           puts stdout "****************************************************************"
           puts stdout "****************************************************************"
           puts stdout "ERROR - duplicate EFDB_Topic = $value"
           puts stdout "****************************************************************"
           puts stdout "****************************************************************"
           exit
        }
        set topics($value) 1
        set tname $value
        puts stdout "Translating $tname"
        set fout [open $SAL_WORK_DIR/idl-templates/[set tname].idl w]
        puts $fout "struct $tname \{"
        add_private_idl $fout
        if { $ctype == "command" } {
           puts $fout "   string<32>	device;
   string<32>	property;
   string<32>	action;
   string<32>	itemValue;"
        }
        if { $ctype == "telemetry" } {
           gentopicdefsql $tname
           set fsql [open $SAL_WORK_DIR/sql/[set tname]_items.sql a]
	   set alias [join [lrange [split $tname "_"] 1 end] "_"]
        }
      }
      if { $tag == "EFDB_Name"} {
        set item $value ; set unit ""
        incr itemid 1
        set desc "" ; set range "" ; set location ""
        set freq 0.054 ; set sdim 1
        if { [lsearch $IDLRESERVED [string tolower $item]] > -1 } {
           puts stdout "****************************************************************"
           puts stdout "****************************************************************"
           puts stdout "Invalid use of IDL reserved token $item"
           puts stdout "****************************************************************"
           puts stdout "****************************************************************"
           exit 1
        }
      }
      if { $tag == "/SALEvent" || $tag == "/SALCommand" } {
           if { [info exists EVENT_ENUM($alias)] } {
             foreach e $EVENT_ENUM($alias) {
               set i 1
               set enum [string trim $e "\{\}"]
               set cnst [lindex [split $enum :] 1]
               foreach id [split $cnst ,] {
                  puts $fout " const long [set alias]_[string trim $id " "]=$i;"
                  incr i 1
               }
             }
             set done($alias) 1
           }
           if { [info exists EVENT_ENUM([set subsys]_shared)] } {
             foreach e $EVENT_ENUM([set subsys]_shared) {
               set i 1
               set enum [string trim $e "\{\}"]
               set cnst [lindex [split $enum :] 1]
               foreach id [split $cnst ,] {
                   puts $fout "	const long [set subsys]_shared_[string trim $id " "]=$i;"
                   incr i 1
               }
             }
             unset EVENT_ENUM([set subsys]_shared)
           }
      }
      if { $tag == "IDL_Type"} {
         set type $value
         if { $type == "long long" } {set type "longlong"}
         if { $type == "unsigned long long" } {set type "unsigned longlong"}
      }
      if { $tag == "IDL_Size"}        {set sdim $value}
      if { $tag == "Description"}     {set desc $value}
      if { $tag == "Frequency"}       {set freq $value}
      if { $tag == "Range"}           {set range $value}
      if { $tag == "Sensor_location"} {set location $value}
      if { $tag == "Count"}           {set idim $value}
      if { $tag == "Units"}           {set unit [string trim $value]}
      if { $tag == "/item" } {
         if { $type == "string" || $type == "char" } {
            if { $sdim > 1 } {
               set declare "   string<[set sdim]> $item;"
            } else {
               set declare "   string $item;"
            }
         } else {
            if { $idim > 1 } {
               set declare "   $type $item\[[set idim]\];"
            } else {
               set declare "   $type $item;"
            }
         }
         set declare [string trim $declare " ;"]
         puts $fout $declare
         set ydec [join [split $declare "\[" ] "("]
         set declare [join [split $ydec "\]" ] ")"]
         if { $ctype == "command" } {
            lappend CMDS($subsys,$alias,param) "$declare"
            lappend CMDS($subsys,$alias,plist)  $item
            if { $unit != "" } {set UNITS($subsys,$alias,$item) $unit}
         }
         if { $ctype == "event" } {
            lappend EVTS($subsys,$alias,param) "$declare"
            lappend EVTS($subsys,$alias,plist) $item
         }
         if { $ctype == "telemetry" } {
	    lappend TLMS($subsys,$alias,param) "$declare"
	    lappend TLMS($subsys,$alias,plist) $item
            puts $fsql "INSERT INTO [set tname]_items VALUES ($itemid,\"$item\",\"$type\",$idim,\"$unit\",$freq,\"$range\",\"$location\",\"$desc\");"
         }
      }
   }
   if { $fout != "" } {
      puts $fout "\};"
      puts $fout "#pragma keylist $tname"
      if { [info exists EVENT_ENUM($alias)] && [info exists done($alias)] == 0} {
        foreach e $EVENT_ENUM($alias) {
          set i 1
          set enum [string trim $e "\{\}"]
          set cnst [lindex [split $enum :] 1]
          foreach id [split $cnst ,] {
              puts $fout " const long [set alias]_[string trim $id " "]=$i;"
              incr i 1
          }
        }
        set done($alias) 1
      }
      if { [info exists EVENT_ENUM([set subsys]_shared)] } {
        foreach e $EVENT_ENUM([set subsys]_shared) {
          set i 1
          set enum [string trim $e "\{\}"]
          set cnst [lindex [split $enum :] 1]
          foreach id [split $cnst ,] {
              puts $fout " const long [set subsys]_shared_[string trim $id " "]=$i;"
              incr i 1
          }
        }
      }
      close $fout
      if { $ctype == "telemetry" } {
        close $fsql
      }
      set alias ""
   }
   close $fin
   puts stdout "itemid for $SAL_WORK_DIR/idl-templates/[set tname].idl=  $itemid"
   if { [info exists CMD_ALIASES($subsys)] } {
    if { $CMD_ALIASES($subsys) != "" } {
     puts stdout "Generating test command gui input"        
     set fout [open $SAL_WORK_DIR/idl-templates/validated/[set subsys]_cmddef.tcl w]
     puts $fout "set CMD_ALIASES($subsys) \"$CMD_ALIASES($subsys)\""
     foreach c [array names CMDS] {
        puts $fout "set CMDS($c) \"$CMDS($c)\""
     }
     close $fout
     genhtmlcommandtable $subsys
    }
   }
   if { [info exists EVENT_ALIASES($subsys)] } {
    if { $EVENT_ALIASES($subsys) != "" } {
     puts stdout "Generating test event gui input"        
     set fout [open $SAL_WORK_DIR/idl-templates/validated/[set subsys]_evtdef.tcl w]
     puts $fout "set EVENT_ALIASES($subsys) \"$EVENT_ALIASES($subsys)\""
     foreach c [array names EVTS] {
        puts $fout "set EVTS($c) \"$EVTS($c)\""
     }
     foreach c [array names EVENT_ENUM] {
        puts $fout "set EVENT_ENUM($c) \"$EVENT_ENUM($c)\""
     }
     foreach c [array names EVENT_ENUMS] {
        puts $fout "set EVENT_ENUMS($c) \"$EVENT_ENUMS($c)\""
     }
     close $fout
     genhtmleventtable $subsys
    }
   }
   if { [info exists TLM_ALIASES($subsys)] } {
    if { $TLM_ALIASES($subsys) != "" } {
      puts stdout "Generating telemetry gui input"
      set fout [open $SAL_WORK_DIR/idl-templates/validated/[set subsys]_tlmdef.tcl w]
      puts $fout "set TLM_ALIASES($subsys) \"$TLM_ALIASES($subsys)\""
      foreach t [array names TLMS] {
         puts $fout "set TLMS($t) \"$TLMS($t)\""
      }
      close $fout
    }
    genhtmltelemetrytable $subsys
   }
}



proc genhtmlcommandtable { subsys } {
global IDLRESERVED SAL_WORK_DIR SAL_DIR CMDS CMD_ALIASES EVTS EVENT_ALIASES UNITS
  exec mkdir -p $SAL_WORK_DIR/html/[set subsys]
  set fout [open $SAL_WORK_DIR/html/[set subsys]/[set subsys]_Commands.html w]
  puts stdout "Generating html command table $subsys"
  puts $fout "<H3>$subsys Commands</H3><P><UL>"
  puts $fout "<TABLE BORDER=3 CELLPADDING=5 BGCOLOR=LightBlue  WIDTH=600>
<TR BGCOLOR=Yellow><B><TD>Command Alias</TD><TD>Parameter</TD></B></TR>"
  foreach i [lsort $CMD_ALIASES($subsys)] {
      set cmd "$CMDS($subsys,$i) - - -"
      puts $fout "<TR><TD>$subsys<BR>$i</TD><TD> "
      if { [info exists CMDS($subsys,$i,param)] } {
        foreach p $CMDS($subsys,$i,param) {
          set id [lindex [split [lindex $p 1] "()"] 0]
          if { [info exists UNITS($subsys,$i,$id)] } {
             puts $fout "$p : $UNITS($subsys,$i,$id)<BR>"
          } else {
             puts $fout "$p<BR>"
          }
        } 
        puts $fout "</TD></TR>"
      } else {
        puts $fout "n/a"
      }
  }
  puts $fout "</TABLE></UL><P>"
  close $fout
}

proc genhtmleventtable { subsys } {
global IDLRESERVED SAL_WORK_DIR SAL_DIR CMDS CMD_ALIASES EVTS EVENT_ALIASES UNITS
  exec mkdir -p $SAL_WORK_DIR/html/[set subsys]
  set fout [open $SAL_WORK_DIR/html/[set subsys]/[set subsys]_Events.html w]
  puts stdout "Generating html logevent table $subsys"
  puts $fout "<H3>$subsys Logevents</H3><P><UL>"
  puts $fout "<TABLE BORDER=3 CELLPADDING=5 BGCOLOR=LightBlue  WIDTH=600>
<TR BGCOLOR=Yellow><B><TD>Log Event Alias</TD><TD>Activity</TD><TD>Event
</TD><TD>Parameter(s)</TD></B></TR>"
  foreach i [lsort $EVENT_ALIASES($subsys)] {
      set evt "$EVTS($subsys,$i) - - -"
      puts $fout "<TR><TD>$subsys<BR>$i</TD><TD>[lindex $evt 0] </TD><TD>[lindex $evt 1] </TD><TD> "
      if { [info exists EVTS($subsys,$i,param)] } {
        foreach p $EVTS($subsys,$i,param) {
          set id [lindex [split [lindex $p 1] "()"] 0]
          if { [info exists UNITS($subsys,$i,$id)] } {
             puts $fout "$p : $UNITS($subsys,$i,$id)<BR>"
          } else {
             puts $fout "$p<BR>"
          }
        } 
        puts $fout "</TD></TR>"
      } else {
        puts $fout "n/a"
      }
  }
  puts $fout "</TABLE></UL><P>"
  close $fout
}



proc genhtmltelemetrytable { subsys } {
global IDLRESERVED SAL_WORK_DIR SAL_DIR TLMS TLM_ALIASES UNITS
  exec mkdir -p $SAL_WORK_DIR/html/[set subsys]
  set fout [open $SAL_WORK_DIR/html/[set subsys]/[set subsys]_Telemetry.html w]
  puts stdout "Generating html telemetry table $subsys"
  puts $fout "<H3>$subsys Telemetry</H3><P><UL>"
  puts $fout "<TABLE BORDER=3 CELLPADDING=5 BGCOLOR=LightBlue  WIDTH=600>
<TR BGCOLOR=Yellow><B><TD>Telemetry Stream</TD><TD>Parameter(s)</TD></B></TR>"
  foreach i [lsort $TLM_ALIASES($subsys)] {
      puts $fout "<TR><TD>[set subsys]_[set i]</TD><TD> "
      if { [info exists TLMS($subsys,$i,param)] } {
        foreach p $TLMS($subsys,$i,param) {
         set id [lindex [split [lindex $p 1] "()"] 0]
         if { [info exists UNITS($subsys,$i,$id)] } {
             puts $fout "$p : $UNITS($subsys,$i,$id)<BR>"
          } else {
             puts $fout "$p<BR>"
          }
        } 
        puts $fout "</TD></TR>"
      } else {
        puts $fout "n/a"
      }
  }
  puts $fout "</TABLE></UL><P>"
  close $fout
}



set IDLRESERVED "abstract any attribute boolean case char component const consumes context custom dec default double emits enum eventtype exception exit factory false finder fixed float getraises home import in inout interface limit local long module multiple native object octet oneway out primarykey private provides public publishes raises readonly sequence setraises short string struct supports switch true truncatable typedef typeid typeprefix union unsigned uses valuebase valuetype void wchar wstring"
set SAL_DIR $env(SAL_DIR)
set SAL_WORK_DIR $env(SAL_WORK_DIR)
source $SAL_DIR/add_private_idl.tcl
source $SAL_DIR/checkidl.tcl


