#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* _Z15GetBattleStructv();
extern "C" void* _Z10GetWord0x0Pi(int*);
extern "C" void func_0203b110(void* obj, int value, int frames);
extern "C" void func_ov017_0218b5b0();

// USA: func_ov001_0215b50c  (semantic: UpdateCounterAndNotify_0215b50c)
extern "C" ARM int func_ov001_0215b50c(void* self, int mode) {
    int value;
    int frames = func_ov017_021d60f4(self);
    value = -16;
    if (mode >= 2) {
        value = func_ov017_021d60f4((char*)self + 0x8);
    }
    void* battle = _Z15GetBattleStructv();
    void* obj = _Z10GetWord0x0Pi((int*)battle);
    if (obj != NULL) {
        func_0203b110(obj, value, frames);
        func_ov017_0218b5b0();
    }
    return 1;
}
