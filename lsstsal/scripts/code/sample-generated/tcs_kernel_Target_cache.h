typedef struct tcs_kernel_Target_cache {
  int cppDummy;
  int syncI;
  char site[32];
  float t0;
  float az;
  float el;
  float azdot;
  float eldot;
  float Wavel;
  float XOffset;
  float YOffset;
  char OffSys[32];
  float focalplaneX;
  float focalplaneY;
  float Temp;
  float Press;
  float Humid;
  float TLR;
  float Tai;
  int syncO;
} tcs_kernel_Target_cache;
