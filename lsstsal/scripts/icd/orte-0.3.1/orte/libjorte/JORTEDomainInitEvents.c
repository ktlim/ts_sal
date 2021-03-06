/* JORTEDomainInitEvents.c */


/**
  * This code provides conversion between JAVA a C environments.
  * The C functions are calling here and results are send to JAVA
  * native functions. It uses the header pregenerated by JAVA
  * (by command 'javah -jni class_with_native_function')
  *
  * @author Lukas Pokorny (lukas_pokorny@centrum.cz)
  * @author CTU FEE Prague - Department of Control Engineering (dce.felk.cvut.cz
)
  * @author Project ORTE - OCERA Real Time Ethernet (www.ocera.org)
  * @author dedication to Kj
  * @version 0.1
  *
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation; either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  * GNU General Public License for more details.
  *
  */

#include <stdlib.h>
// origin orte headers
#include "orte.h"
// pregenerated header
#include "jorte/org_ocera_orte_types_DomainEvents.h"
#include "jorte/4all.h"

JNIEXPORT jint JNICALL
Java_org_ocera_orte_types_DomainEvents_jORTEDomainInitEvents
(JNIEnv *env, jclass cls)
{
  ORTEDomainAppEvents *evs;

  // memory allocation
  evs = (ORTEDomainAppEvents *) malloc(sizeof(ORTEDomainAppEvents));
  if(evs == 0)
  {
    printf(":!c: evs = NULL [not enough memory] \n");
    return 0;
  }
  // call the liborte function
  if (!ORTEDomainInitEvents(evs))
  {
    printf(":!c: events not initialized! \n");
    free(evs);
    return 0;
  }
  #ifdef TEST_STAGE
     printf(":c: events initialized.. \n");
  #endif

  return ((jint) evs);

}
