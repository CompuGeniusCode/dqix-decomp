#include <globaldefs.h>

extern "C" void func_ov003_0217da48(void* obj);

struct Struct020dae68 {
    unsigned char pad0[0xc];
    void* field_c;
};

// USA: func_020dae68
ARM void ReleaseResource020dae68(Struct020dae68* p) {
    void* obj = p->field_c;
    if (obj != NULL) {
        func_ov003_0217da48(obj);
    }
}
