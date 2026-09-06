#include <globaldefs.h>
#include "System/Cache.h"

extern "C" extern int LoadToMainBG2ScreenData(int arg0, int arg1, unsigned int arg2);

extern unsigned char* data_ov031_02290ce8;

// USA: func_ov031_02234fa4  (semantic: FlushAndTransferCharBase_02234fa4)
extern "C" ARM void func_ov031_02234fa4(void) {
    if (data_ov031_02290ce8[0x604] == 0) {
        return;
    }
    CleanInvalidateCacheRange(data_ov031_02290ce8 + 4, 0x600);
    LoadToMainBG2ScreenData((int)(data_ov031_02290ce8 + 4), 0, 0x600);
    data_ov031_02290ce8[0x604] = 0;
}
