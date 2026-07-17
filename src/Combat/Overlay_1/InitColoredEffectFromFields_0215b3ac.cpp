#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_020704fc(void*);
struct EffectParam02070900;
struct Rgb02070900;
void SetColoredEffectParam02070900(struct EffectParam02070900*, struct Rgb02070900*, unsigned int);

struct Rgb0215b3ac { unsigned int r, g, b; };

// USA: func_ov001_0215b3ac
ARM int InitColoredEffectFromFields_0215b3ac(void* self) {
    Rgb0215b3ac rgb;
    rgb.r = func_ov017_021d60f4(self);
    rgb.g = func_ov017_021d60f4((char*)self + 0x8);
    rgb.b = func_ov017_021d60f4((char*)self + 0x10);
    unsigned int v = func_ov017_021d60f4((char*)self + 0x18);
    void* handle = func_020704fc((void*)v);
    if (handle != NULL) {
        SetColoredEffectParam02070900((struct EffectParam02070900*)handle, (struct Rgb02070900*)&rgb, v);
    }
    return 1;
}
