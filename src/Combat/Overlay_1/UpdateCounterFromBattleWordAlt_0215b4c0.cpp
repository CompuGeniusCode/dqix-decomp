#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* _Z15GetBattleStructv();
extern "C" void* _Z10GetWord0x0Pi(int*);
extern "C" void func_0203b110(void* obj, int value, int frames);
extern "C" void func_ov017_0218b5b0();

// USA: func_ov001_0215b4c0
ARM int UpdateCounterFromBattleWordAlt_0215b4c0(void* self, int mode) {
    int frames = func_ov017_021d60f4(self);
    if (mode >= 2) {
        func_ov017_021d60f4((char*)self + 0x8);
    }
    void* battle = _Z15GetBattleStructv();
    void* obj = _Z10GetWord0x0Pi((int*)battle);
    if (obj != NULL) {
        func_0203b110(obj, 0, frames);
        func_ov017_0218b5b0();
    }
    return 1;
}
