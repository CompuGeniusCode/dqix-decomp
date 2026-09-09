#include <globaldefs.h>

extern int strDataSoundBgmSdat;
extern int data_ov032_02200180;

extern "C" int OpenFileStreamInRegion(void*, void*, void*, int, int);

// USA: func_0209c2b8
// The only file path in this function's literal pool is "data/sound/bgm.sdat".
extern "C" ARM int OpenBgmStreamLargeRegion(void* ctx) {
    return OpenFileStreamInRegion(ctx, &strDataSoundBgmSdat, &data_ov032_02200180, 0xa2000, 1);
}
