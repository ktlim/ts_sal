/* Standard includes needed... */
#include <tcl.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <NDDS.h>


#include "steInternalState.h"
#include "steInternalState_tclndds.h"

int 
Tcl2Ndds_steInternalState (steInternalState nddsObj, int argc, char **argv) {
  int count = 0;
  int i;

  if (steInternalState_ArgCount != argc) {
    fprintf (stderr,"ERROR(tcl2ndds): wrong arg count for steInternalState.\n");
    fprintf (stderr,"                 got %d, expected %d\n",argc,steInternalState_ArgCount);
    return (-1);
  }

  sscanf  (argv[count++], "%ld", &nddsObj->stateMask );
  sscanf  (argv[count++], "%u", &nddsObj->cameraDesignator);
  sscanf  (argv[count++], "%u", &nddsObj->msecs     );
  sscanf  (argv[count++], "%u", &nddsObj->week      );

  return (count);	/* # args used in this struct. */
} /* steInternalStateStruct */


int 
Ndds2Tcl_steInternalState (steInternalState nddsObj, Tcl_Interp *interp) {
  char tmpStr[256];
  int  i;
  char *newValue;

  sprintf (tmpStr, "%ld", nddsObj->stateMask );  newValue = Tcl_SetVar2 (interp, "this", "stateMask", tmpStr, TCL_LEAVE_ERR_MSG);
  sprintf (tmpStr, "%u", nddsObj->cameraDesignator);  newValue = Tcl_SetVar2 (interp, "this", "cameraDesignator", tmpStr, TCL_LEAVE_ERR_MSG);
  sprintf (tmpStr, "%u", nddsObj->msecs     );  newValue = Tcl_SetVar2 (interp, "this", "msecs", tmpStr, TCL_LEAVE_ERR_MSG);
  sprintf (tmpStr, "%u", nddsObj->week      );  newValue = Tcl_SetVar2 (interp, "this", "week", tmpStr, TCL_LEAVE_ERR_MSG);

  return (1==1);	/* Return TRUE for now. */
} /* steInternalStateStruct */

