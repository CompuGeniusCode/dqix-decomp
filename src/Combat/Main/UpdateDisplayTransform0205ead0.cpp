#include <globaldefs.h>

void Forward0203aa80(void* obj, int arg2);
int GetFromField00203aa64(void* obj);
int DispatchIndexedCommand0203aa98(void*, int);

struct Obj_0205ead0 {
    char pad0[0xb8];
    int fb8;
    short fbc;
    char pad1[0xc0 - 0xbe];
    int fc0;
};

// USA: func_0205ead0
ARM void UpdateDisplayTransform0205ead0(struct Obj_0205ead0* a, int b, int c) {
    Forward0203aa80(a, a->fb8);
    DispatchIndexedCommand0203aa98(a, b);
    a->fbc = c;
    a->fc0 = GetFromField00203aa64(a);
}
