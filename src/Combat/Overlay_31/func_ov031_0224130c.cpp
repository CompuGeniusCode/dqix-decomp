#include <globaldefs.h>

extern "C" ARM void func_ov031_0224130c(void);
ARM void ResetAndInit32_02241318(void);
struct Obj022078f0;
ARM int Validate_022078f0(Obj022078f0* obj, void* v);
extern "C" ARM int func_ov031_02207434(int a);
ARM int SelectAndCall022071d8(int unused, int mode);

struct Target20_02241338 {
    char pad[0x810];
    void (*field0x810)(void);
    int field0x814;
    int field0x818;
};

struct Self02241338 {
    char pad0[0x8];
    int field0x8;
    char pad0xc[0x18 - 0xc];
    int field0x18;
    int field0x1c;
    Target20_02241338* field0x20;
};

// USA: func_ov031_02241338  (semantic: ProcessAndValidate32_02241338)
extern "C" ARM int func_ov031_02241338(Self02241338* self) {
    typedef int (*Fn3_02241338)(int, int, int);
    int r = ((Fn3_02241338)SelectAndCall022071d8)(2, 1, 0);
    if (r >= 0) {
        if (self->field0x8 != 0) {
            ResetAndInit32_02241318();
            self->field0x20->field0x814 = self->field0x1c;
            self->field0x20->field0x818 = self->field0x18;
            self->field0x20->field0x810 = func_ov031_0224130c;
            if (Validate_022078f0((Obj022078f0*)r, self->field0x20) < 0) {
                func_ov031_02207434(r);
                r = -1;
            }
        }
    }
    return r;
}
