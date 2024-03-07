//////////////////////////////////////////////////////
// Developed by A0zhar
//////////////////////////////////////////////////////
#include "../libPS4/include/ps4.h"
#include "headers/setup.h"


#define ORBIS_OK                                        0x00000000
#define ORBIS_VIDEO_USER_MAIN                           0xFF
#define SCE_VIDEO_OUT_BUS_TYPE_MAIN                     0
#define SCE_VIDEO_OUT_BUS_TYPE_AUX                      5
#define SCE_VIDEO_OUT_BUS_TYPE_AUX_SOCIAL_SCREEN        5
#define SCE_VIDEO_OUT_BUS_TYPE_AUX_GAME_LIVE_STREAMING  6
#define SCE_VIDEO_OUT_BUS_TYPE_COUNT                    7

//
// Function, will get the current screen dimenstions (width and height)
bool SERGetCurrentScreenSize(int *destW, int *destH) {
     int handle = -1;
     SceVideoOutResolutionStatus rs;
     memset(&rs, 0, sizeof(rs));
     
     handle = sceVideoOutOpen(ORBIS_VIDEO_USER_MAIN, SCE_VIDEO_OUT_BUS_TYPE_MAIN, 0, 0);
     if (handle == -1) return false;

     int rsu = sceVideoOutGetResolutionStatus(handle, &rs);
     if (rsu == ORBIS_OK) {
         *destW = rs.fullWidth;
         *destH = rs.fullHeight;
         return true;
     }
  
     return false;
}