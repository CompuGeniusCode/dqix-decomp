#include <globaldefs.h>

extern "C" void func_020b6acc(unsigned int a, void* b, int n);

struct Obj020b4514 {
    unsigned char* field_0;   // 0x0
    char pad0[4];              // 0x4
    int field_8;                // 0x8
    char pad1[0xc];               // 0xc
    void (*fn)(void*);              // 0x18
    char pad2[0x8f - 0x1c];           // 0x1c
    unsigned char field_8f;            // 0x8f
};

// USA: func_020b4514
ARM void Dispatch020b4514(struct Obj020b4514* self) {
    int flags = self->field_8;
    if (!(flags & 0x200) && (flags & 0x1)) {
        int mode = (self->fn != NULL) ? self->field_8f : 0;
        int flag2;
        if (mode == 1) {
            self->field_8 &= ~0x40;
            self->fn(self);
            mode = (self->fn != NULL) ? self->field_8f : 0;
            flag2 = self->field_8 & 0x40;
        } else {
            flag2 = 0;
        }

        if (flag2 == 0) {
            int b = self->field_0[1];
            if (!(self->field_8 & 0x100)) {
                func_020b6acc(0x14, &b, 1);
            }
        }

        if (mode == 3) {
            self->field_8 &= ~0x40;
            self->fn(self);
        }
    }
    self->field_0 += 2;
}
