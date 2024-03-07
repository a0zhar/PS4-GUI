#pragma once
#ifndef _SETUP_HH
#define _SETUP_HH
#include "videoout_types.h"


typedef int SceUserServiceUserId;

extern int(*sceVideoOutClose)(int32_t handle);
extern int(*sceVideoOutGetResolutionStatus)(int32_t handle, SceVideoOutResolutionStatus *status);
extern int(*sceVideoOutOpen)(SceUserServiceUserId userId, int32_t type, int32_t index, const void *param);
extern int(*sceVideoOutRegisterBuffers)(int32_t handle, int32_t startIndex, void *const *addresses, int32_t bufferNum, const SceVideoOutBufferAttribute *attribute);
extern int(*sceVideoOutRegisterStereoBuffers)(int32_t handle, int32_t startIndex, const SceVideoOutStereoBuffers *buffers, int32_t bufferNum, const SceVideoOutBufferAttribute *attribute);
extern int(*sceVideoOutSetBufferAttribute)(SceVideoOutBufferAttribute *attribute, uint32_t pixelFormat, uint32_t tilingMode, uint32_t aspectRatio, uint32_t width, uint32_t height, uint32_t pitchInPixel);
extern int(*sceVideoOutSetFlipRate)(int32_t handle, int32_t rate);
extern int(*sceVideoOutAddFlipEvent)(void);
extern int(*sceVideoOutAdjustColor_)(void);
extern int(*sceVideoOutColorSettingsSetGamma_)(void);
extern int(*sceVideoOutConfigureOutputMode_)(void);
extern int(*sceVideoOutGetDeviceCapabilityInfo_)(void);
extern int(*sceVideoOutGetEventData)(void);
extern int(*sceVideoOutGetFlipStatus)(int32_t handle, SceVideoOutFlipStatus *status);
extern int(*sceVideoOutIsFlipPending)(void);
extern int(*sceVideoOutModeSetAny_)(void);
extern int(*sceVideoOutSetWindowModeMargins)(void);
extern int(*sceVideoOutSubmitChangeBufferAttribute)(void);
extern int(*sceVideoOutSubmitFlip)(void);
extern int(*sceVideoOutWaitVblank)(void);
extern int(*sceVideoOutGetVblankStatus)(void);
void setupVideoOutFunctions();

#endif