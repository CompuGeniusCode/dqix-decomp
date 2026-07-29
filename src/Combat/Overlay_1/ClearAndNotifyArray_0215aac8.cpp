#include <globaldefs.h>

int GetData02104304Field4(void);
extern "C" void func_020301c8(int, int);
extern int data_ov001_021658e0[];
struct S0215aac8 { char pad[0x88]; int count; };
extern S0215aac8 data_ov001_021658b8;

// USA: func_ov001_0215aac8  (semantic: ClearAndNotifyArray_0215aac8)
extern "C" ARM void func_ov001_0215aac8(void) {
    int x = GetData02104304Field4();
    int i;
    for (i = 0; i < data_ov001_021658b8.count; i++) {
        func_020301c8(x, data_ov001_021658e0[i]);
        data_ov001_021658e0[i] = -1;
    }
    data_ov001_021658b8.count = 0;
}
