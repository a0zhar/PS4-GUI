#include "../libPS4/include/ps4.h"
#include "headers/setup.h"

bool hasBeenSetupBefore = false;

int(*sceVideoOutClose)(int32_t handle);
int(*sceVideoOutGetResolutionStatus)(int32_t handle, SceVideoOutResolutionStatus *status);
int(*sceVideoOutOpen)(SceUserServiceUserId userId, int32_t type, int32_t index, const void *param);
int(*sceVideoOutRegisterBuffers)(int32_t handle, int32_t startIndex, void *const *addresses, int32_t bufferNum, const SceVideoOutBufferAttribute *attribute);
int(*sceVideoOutRegisterStereoBuffers)(int32_t handle, int32_t startIndex, const SceVideoOutStereoBuffers *buffers, int32_t bufferNum, const SceVideoOutBufferAttribute *attribute);
int(*sceVideoOutSetBufferAttribute)(SceVideoOutBufferAttribute *attribute, uint32_t pixelFormat, uint32_t tilingMode, uint32_t aspectRatio, uint32_t width, uint32_t height, uint32_t pitchInPixel);
int(*sceVideoOutSetFlipRate)(int32_t handle, int32_t rate);
int(*sceVideoOutAddFlipEvent)(void);
int(*sceVideoOutAdjustColor_)(void);
int(*sceVideoOutColorSettingsSetGamma_)(void);
int(*sceVideoOutConfigureOutputMode_)(void);
int(*sceVideoOutGetDeviceCapabilityInfo_)(void);
int(*sceVideoOutGetEventData)(void);
int(*sceVideoOutGetFlipStatus)(int32_t handle, SceVideoOutFlipStatus *status);
int(*sceVideoOutIsFlipPending)(void);
int(*sceVideoOutModeSetAny_)(void);
int(*sceVideoOutSetWindowModeMargins)(void);
int(*sceVideoOutSubmitChangeBufferAttribute)(void);
int(*sceVideoOutSubmitFlip)(void);
int(*sceVideoOutWaitVblank)(void);
int(*sceVideoOutGetVblankStatus)(void);

#define _INVALID_HANDLE -1

bool loadSystemModuleByName(const char *moduleName, int *hDest) {
	int handle = _INVALID_HANDLE;

	// Load the module, and check if the module was loaded
	// successfully...
	handle = sceKernelLoadStartModule(moduleName, 0, NULL, 0, 0, 0);
	if (handle == _INVALID_HANDLE)
		return false;

	*hDest = handle;
	return true;
}

void setupVideoOutFunctions() {
	if (hasBeenSetupBefore) return;

	int hVideoOut;
	if (!loadSystemModuleByName("libSceVideoOut.sprx", &hVideoOut))
		return;

	//
	// Import the functions, from within the libSceVideoOut module
	//

	RESOLVE(hVideoOut, sceVideoOutClose);
	RESOLVE(hVideoOut, sceVideoOutGetResolutionStatus);
	RESOLVE(hVideoOut, sceVideoOutOpen);
	RESOLVE(hVideoOut, sceVideoOutRegisterBuffers);
	RESOLVE(hVideoOut, sceVideoOutRegisterStereoBuffers);
	RESOLVE(hVideoOut, sceVideoOutSetBufferAttribute);
	RESOLVE(hVideoOut, sceVideoOutSetFlipRate);
	RESOLVE(hVideoOut, sceVideoOutAddFlipEvent);
	RESOLVE(hVideoOut, sceVideoOutAdjustColor_);
	RESOLVE(hVideoOut, sceVideoOutColorSettingsSetGamma_);
	RESOLVE(hVideoOut, sceVideoOutConfigureOutputMode_);
	RESOLVE(hVideoOut, sceVideoOutGetDeviceCapabilityInfo_);
	RESOLVE(hVideoOut, sceVideoOutGetEventData);
	RESOLVE(hVideoOut, sceVideoOutGetFlipStatus);
	RESOLVE(hVideoOut, sceVideoOutIsFlipPending);
	RESOLVE(hVideoOut, sceVideoOutModeSetAny_);
	RESOLVE(hVideoOut, sceVideoOutSetWindowModeMargins);
	RESOLVE(hVideoOut, sceVideoOutSubmitChangeBufferAttribute);
	RESOLVE(hVideoOut, sceVideoOutSubmitFlip);
	RESOLVE(hVideoOut, sceVideoOutWaitVblank);
	RESOLVE(hVideoOut, sceVideoOutGetVblankStatus);
	hasBeenSetupBefore = true;	
}