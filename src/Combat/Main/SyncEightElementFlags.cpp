#include <globaldefs.h>

extern "C" void* func_0205ec34(void);
int TestBitInByteArray(int unused, unsigned char* arr, int index);
extern "C" void func_020aea40(unsigned char index, unsigned char isSet);
extern unsigned short data_020e9138[];

// USA: func_020ae9f0
ARM void SyncEightElementFlags(void) {
    unsigned char* obj = (unsigned char*)func_0205ec34();
    int i;
    for (i = 0; i < 8; i++) {
        int isSet = TestBitInByteArray((int)obj, obj + 0x8c, data_020e9138[i]);
        func_020aea40(i, isSet);
    }
}
