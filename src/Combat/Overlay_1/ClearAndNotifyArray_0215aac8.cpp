#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern int data_ov001_021658e0[];
struct S0215aac8 { char pad[0x88]; int count; };
extern S0215aac8 data_ov001_021658b8;

// USA: func_ov001_0215aac8  (semantic: ClearAndNotifyArray_0215aac8)
extern "C" ARM void func_ov001_0215aac8(void) {
    int x = (int)BackgroundLoader::GetInstance();
    int i;
    for (i = 0; i < data_ov001_021658b8.count; i++) {
        ((BackgroundLoader*)(x))->RemoveTask((int)(data_ov001_021658e0[i]));
        data_ov001_021658e0[i] = -1;
    }
    data_ov001_021658b8.count = 0;
}
