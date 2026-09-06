#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* _Z15GetBattleStructv();
extern "C" void* _Z10GetWord0x0Pi(int*);
extern "C" void func_0203b19c(void* obj, int value, int frames);
extern "C" char* func_ov017_0218b5b0(void);

// USA: func_ov001_0215b454  (semantic: UpdateCounterAndSetFlagB_0215b454)
extern "C" ARM int func_ov001_0215b454(void* self, int mode) {
    int value;
    int frames = func_ov017_021d60f4(self);
    value = -16;
    if (mode >= 2) {
        value = func_ov017_021d60f4((char*)self + 0x8);
    }
    void* battle = _Z15GetBattleStructv();
    void* obj = _Z10GetWord0x0Pi((int*)battle);
    if (obj != NULL) {
        func_0203b19c(obj, value, frames);
        char* q = *(char**)(func_ov017_0218b5b0() + 0x3000 + 0x734);
        if (*(unsigned short*)(q + 0xa) <= 3) {
            *(unsigned char*)(q + 0x102) = 1;
        }
    }
    return 1;
}
