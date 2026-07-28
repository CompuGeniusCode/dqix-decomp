#include <globaldefs.h>
#include "System/DMA.h"

void SetPowerRegisterMode020c3f44(int mode);
extern int data_020f2270;
extern int data_02111240[];

// USA: func_020c61e8
extern "C" ARM void func_020c61e8(void) {
    if (data_020f2270 != -1) {
        AwaitDMACompletion(data_020f2270);
    }
    SetPowerRegisterMode020c3f44(data_02111240[5]);
    data_02111240[5] = 0;
    data_02111240[4] = 0;
    data_02111240[3] = 0;
}
