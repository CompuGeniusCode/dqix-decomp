#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* _Z15GetBattleStructv();
extern "C" void* _Z10GetWord0x0Pi(int*);
void SetBothCounters(void* obj, int value, int frames);
extern "C" void func_ov017_0218b5b0();

// USA: func_ov001_0215b2cc  (semantic: UpdateCounterAndNotify_0215b2cc)
extern "C" ARM int func_ov001_0215b2cc(void* self, int mode) {
    int frames = func_ov017_021d60f4(self);
    if (mode >= 2) {
        func_ov017_021d60f4((char*)self + 0x8);
    }
    void* battle = _Z15GetBattleStructv();
    void* obj = _Z10GetWord0x0Pi((int*)battle);
    if (obj != NULL) {
        SetBothCounters(obj, 0, frames);
        func_ov017_0218b5b0();
    }
    return 1;
}
