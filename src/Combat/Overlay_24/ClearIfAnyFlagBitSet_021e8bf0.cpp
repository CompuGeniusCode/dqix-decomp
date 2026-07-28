#include <globaldefs.h>

struct Flags_021e8bf0 {
    unsigned char b0:1;
    unsigned char b1:1;
    unsigned char b2:1;
    unsigned char b3:1;
    unsigned char b4:1;
    unsigned char b5:1;
    unsigned char b6:1;
    unsigned char b7:1;
};

// USA: func_ov024_021e8bf0  (semantic: ClearIfAnyFlagBitSet_021e8bf0)
extern "C" ARM void func_ov024_021e8bf0(void* unused0, char* obj, short* out2) {
    struct Flags_021e8bf0* f = (struct Flags_021e8bf0*)(obj + 0x1c);
    if (f->b2 || f->b1 || f->b3 || f->b4 || f->b5 || f->b6) {
        *out2 = 0;
    }
}
