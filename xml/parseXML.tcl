#!/usr/bin/tclsh

proc parseXMLtoidl { fname } { 
global IDLRESERVED SAL_WORK_DIR SAL_DIR
   set fin [open $fname r]
   set fout ""
   while { [gets $fin rec] > -1 } {
      set tag   [lindex [split $rec "<>"] 1]
      set value [lindex [split $rec "<>"] 2]
      if { $tag == "SALTelemetry" } {set ctype "telemetry"}
      if { $tag == "SALCommand" }   {set ctype "command"}
      if { $tag == "SALEvent" }     {set ctype "event"}
      if { $tag == "EFDB_Topic" } {
        set itemid 0
        if { $fout != "" } {
           puts $fout "\};"
           puts $fout "#pragma keylist $tname"
           close $fout
           close $fsql
        }
        set tname $value
        puts stdout "Translating $tname"
        set fout [open $SAL_WORK_DIR/[set tname].idl w]
        puts $fout "struct $tname \{"
        add_private_idl $fout
        if { $ctype =="command" } {
           puts $fout "   string<32>	device;
   string<32>	property;
   string<32>	action;
   string<32>	value;"
        }
        if { $ctype == "telemetry" } {
           gentopicdefsql $tname
           set fsql [open $SAL_DIR/code/sql/[set tname]_items.sql a]
        }
      }
      if { $tag == "EFDB_Name"} {
        set item $value ; set unit ""
        incr itemid 1
        set desc "" ; set range "" ; set location ""
        set freq 0.054
        if { [lsearch $IDLRESERVED [string tolower $item]] > -1 } {
           puts stdout "Invalid use of IDL reserved token $id"
           exit 1
        }
      }
      if { $tag == "IDL_Type"}        {set type $value}
      if { $tag == "Description"}     {set desc $value}
      if { $tag == "Frequency"}       {set freq $value}
      if { $tag == "Range"}           {set range $value}
      if { $tag == "Sensor_location"} {set location $value}
      if { $tag == "Count"}           {set idim $value}
      if { $tag == "Units"}           {set unit $value}
      if { $tag == "/item" } {
         if { $type == "string" } {
            if { $idim > 1 } {
               puts $fout "   string<[set idim]> $item ; $unit ; $desc"
            } else {
               puts $fout "   string $item ; $unit; $desc"
            }
         } else {
            if { $idim > 1 } {
               puts $fout "   $type $item\[[set idim]\] ; $unit ; $desc"
            } else {
               puts $fout "   $type $item ; $unit; $desc"
            }
         }
         puts $fsql "INSERT INTO [set tname]_items VALUES ($itemid,\"$item\",\"$type\",$idim,\"$unit\",$freq,\"$range\",\"$location\",\"$desc\");"
      }
   }
   if { $fout != "" } {
      puts $fout "\};"
      puts $fout "#pragma keylist $tname"
      close $fout
      close $fsql
   }
   close $fin
}


set IDLRESERVED "abstract any attribute boolean case char component const consumes context custom default double emits enum eventtype exception factory false finder fixed float getraises home import in inout interface local long module multiple native object octet oneway out primarykey private provides public publishes raises readonly sequence setraises short string struct supports switch true truncatable typedef typeid typeprefix union unsigned uses valuebase valuetype void wchar wstring"
set SAL_DIR $env(SAL_DIR)
set SAL_WORK_DIR $env(SAL_WORK_DIR)
source $SAL_DIR/add_private_idl.tcl
source $SAL_DIR/checkidl.tcl


