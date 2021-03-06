/*
 *  $Id: globals.h,v 0.0.0.1            2003/08/21 
 *
 *  AUTHOR: Petr Smolik                 petr.smolik@wo.cz
 *
 *  ORTE - OCERA Real-Time Ethernet     http://www.ocera.org/
 *  --------------------------------------------------------------------
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 */

#ifndef _GLOBALS_H
#define _GLOBALS_H

#ifdef __cplusplus
extern "C" {
#endif

//debug.c
extern int db_level;
extern int debugLevels[MAX_DEBUG_SECTIONS];
extern int mem_check_counter;
extern NtpTime zNtpTime,iNtpTime;
extern SequenceNumber noneSN;

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif /* _GLOBALS_H */
