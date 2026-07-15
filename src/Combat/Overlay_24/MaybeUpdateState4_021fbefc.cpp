#include <globaldefs.h>

struct S_state4_021fbefc {
    char unk[0xc];
    int state;
};

extern "C" void func_ov024_021fd954(struct S_state4_021fbefc* obj, int mode);

// USA: func_ov024_021fbefc
ARM void MaybeUpdateState4_021fbefc(struct S_state4_021fbefc* obj) {
    if (obj->state >= 3) {
        func_ov024_021fd954(obj, 4);
    }
}
