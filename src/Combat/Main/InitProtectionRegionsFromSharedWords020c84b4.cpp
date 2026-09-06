#include <globaldefs.h>

extern "C" int func_020c8548(int);
extern "C" int func_020c862c(int);
void SetSharedWordDc4(int index, int value);
void SetSharedWordDa0(int index, int value);
unsigned int SetData020f2284();
void SetProtectionRegion1(unsigned int value);
void SetProtectionRegion2(unsigned int value);

extern int data_0211155c;

// USA: func_020c84b4  (semantic: InitProtectionRegionsFromSharedWords020c84b4)
extern "C" ARM void func_020c84b4(void) {
    int v1 = func_020c8548(2);
    SetSharedWordDc4(2, v1);
    int v2 = func_020c862c(2);
    SetSharedWordDa0(2, v2);

    int flag = *(int*)((char*)&data_0211155c + 0x4);
    if (flag != 0) {
        unsigned int r = SetData020f2284();
        if ((r & 0x3) != 0x1) {
            return;
        }
    }
    SetProtectionRegion1(0x200002b);
    SetProtectionRegion2(0x23e0021);
}
