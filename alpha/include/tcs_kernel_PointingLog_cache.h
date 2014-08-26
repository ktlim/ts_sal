typedef struct tcs_kernel_PointingLog_cache {
  int cppDummy;
  int syncI;
  int syncO;
  char private_revCode[32];
  long private_sndStamp;
  long private_rcvStamp;
  long private_seqNum;
  long private_origin;
  float Ra;
  float Dec;
  float Wavel;
  float Roll;
  float Pitch;
  float Casspa;
  float Xr;
  float Yr;
  float Fl;
  float Temp;
  float Press;
  float Humid;
  float Tlr;
  float Rcorr;
  float Aux[3];
  long Marked;
} tcs_kernel_PointingLog_cache;
