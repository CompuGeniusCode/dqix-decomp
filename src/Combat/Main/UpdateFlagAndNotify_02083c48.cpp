#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_02191aac(char* obj, int mode, int idx, unsigned char mask);
void EnqueueEventTag17_021ce014(int a, unsigned short b, unsigned short c, unsigned short d);

// USA: func_02083c48  (semantic: UpdateFlagAndNotify_02083c48)
extern "C" ARM void func_02083c48(char* obj, int doEnqueue, int doNotify) {
    obj[0x56c] = 0;
    if (doNotify) {
        short v = *(short*)(obj + 0x568);
        func_ov017_02191aac((char*)func_ov017_0218b5b0(), 0, v, 2);
    }
    if (doEnqueue) {
        unsigned short v = *(unsigned short*)(obj + 0x568);
        EnqueueEventTag17_021ce014(0, 1, 0, v);
    }
}
