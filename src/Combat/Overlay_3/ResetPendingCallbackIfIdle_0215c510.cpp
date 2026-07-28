#include <globaldefs.h>

int IsAnimationActive0209ca2c(void* obj);
int GetData02104304Field4(void);
extern "C" void func_02030110(int x);
extern "C" void func_020301c8(int a, int b);
extern int data_02109bf4;

// USA: func_ov003_0215c510  (semantic: ResetPendingCallbackIfIdle_0215c510)
extern "C" ARM void func_ov003_0215c510(char* obj) {
    if (IsAnimationActive0209ca2c(&data_02109bf4) != 0) return;
    if (*(unsigned char*)(obj + 0x59d) != 0) return;

    int x = GetData02104304Field4();
    func_02030110(x);
    func_020301c8(x, *(int*)(obj + 0x578));
    *(int*)(obj + 0x578) = -1;
    *(unsigned char*)(obj + 0x588) = 0xb;
    *(unsigned char*)(obj + 0x580) = 0;
}
