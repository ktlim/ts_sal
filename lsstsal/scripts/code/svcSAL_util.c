#include <time.h>
#include "string.h"
#include "stdio.h"
#include <sys/time.h>
#include "svcSAL.h"

int svcSAL_sleep(unsigned long milisec)  
{  
     struct timespec req={0,0};  
     time_t sec=(int)(milisec/1000);  
     milisec=milisec-(sec*1000);  
     req.tv_sec=sec;  
     req.tv_nsec=milisec*1000000L;  
     while(nanosleep(&req,&req)==-1)  
       continue;  
     return 1;  
}


int svcSAL_nsleep(unsigned long nanosec)  
{  
     struct timespec req={0,0};  
     time_t sec=0;  
     req.tv_sec=sec;  
     req.tv_nsec=nanosec;  
     while(nanosleep(&req,&req)==-1)  
       continue;  
     return 1;  
}

long svcSAL_timestamp()  
{  
     struct timeval now;
     struct timezone zone;
     long ts;

     gettimeofday(&now, &zone);
     ts = now.tv_sec*1000 + now.tv_usec/1000.;
     return ts;
}

char *svcSAL_errortext(int errorcode)
{
     switch (errorcode) {
         case SAL__OK               : return "OK";
         case SAL__ERR              : return "ERROR";
         case SAL__ILLEGAL_REVCODE  : return "Illegal code revision clash";
         case SAL__TOO_MANY_HANDLES : return "Exhausted svcSAL handle space";
         case SAL__NOT_DEFINED      : return "Unknown subsystem name";
         case SAL__CMD_NOPERM       : return "Not permitted";
         case SAL__CMD_NOACK        : return "Initial ack not received";
         case SAL__CMD_FAILED       : return "Command failed";
         case SAL__CMD_ABORTED      : return "Command aborted by processor";
         case SAL__CMD_TIMEOUT      : return "Command timeout";
     }
     return "Illegal error code - unknown in svcSAL_errortext";
}

char *svcSAL_infotext(int infocode)
{
     switch (infocode) {
         case SAL__OK               : return "OK";
     }
     return "Illegal info code - unknown in svcSAL_infotext";
}

int svcSAL_printarrayi(int isize,int *array,char *tostring) {
    char buf[32760];
    char num[16];

    buf[0]=NULL;
    if (size > 2000) return SAL__ERR;

    for (j=1;j<isize;j++) {
      i[j]=j;
      sprintf(num,"%16ld",i[j]);
      strcat(buf,num);
      if (strlen(buf) > 32744) return SAL_ERR;
    }
    return SAL__OK;

}


