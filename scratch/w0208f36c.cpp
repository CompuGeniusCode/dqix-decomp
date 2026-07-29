#include <globaldefs.h>

struct Shorts5c_374e0;
void SetShorts0x5cTo0x60(struct Shorts5c_374e0* obj, short a, short b, short c);
extern "C" void func_020370a0(void* p, int a, int b);

struct Obj0208f36c {
    char pad[8];
    struct Shorts5c_374e0* field8;
};

// USA: func_0208f36c
ARM void SetField8AndInitShorts_0208f36c(Obj0208f36c* self, struct Shorts5c_374e0* p) {
    self->field8 = p;
    if (p) {
        SetShorts0x5cTo0x60(p, 0x10a, 0x10a, 0x10a);
        func_020370a0(self->field8, 0, 0);
    }
}
