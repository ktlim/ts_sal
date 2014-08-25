/* Standard includes needed... */
#include <tcl.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <NDDS.h>


#include "rtEmergencySignals.h"
#include "rtEmergencySignals_tclndds.h"

int 
Tcl2Ndds_rtEmergencySignals (rtEmergencySignals nddsObj, int argc, char **argv) {
  int count = 0;
  int i;

  if (rtEmergencySignals_ArgCount != argc) {
    fprintf (stderr,"ERROR(tcl2ndds): wrong arg count for rtEmergencySignals.\n");
    fprintf (stderr,"                 got %d, expected %d\n",argc,rtEmergencySignals_ArgCount);
    return (-1);
  }

  {
    int num;
    sscanf  (argv[count++], "%d", &num);
    nddsObj->rtEStop = (char)num;
  }
  {
    int num;
    sscanf  (argv[count++], "%d", &num);
    nddsObj->rtKillSwitch = (char)num;
  }

  return (count);	/* # args used in this struct. */
} /* rtEmergencySignalsStruct */


int 
Ndds2Tcl_rtEmergencySignals (rtEmergencySignals nddsObj, Tcl_Interp *interp) {
  char tmpStr[256];
  int  i;
  char *newValue;

  sprintf (tmpStr, "%d", nddsObj->rtEStop   );  newValue = Tcl_SetVar2 (interp, "this", "rtEStop", tmpStr, TCL_LEAVE_ERR_MSG);
  sprintf (tmpStr, "%d", nddsObj->rtKillSwitch);  newValue = Tcl_SetVar2 (interp, "this", "rtKillSwitch", tmpStr, TCL_LEAVE_ERR_MSG);

  return (1==1);	/* Return TRUE for now. */
} /* rtEmergencySignalsStruct */

