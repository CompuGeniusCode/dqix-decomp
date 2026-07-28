#include <globaldefs.h>

struct S02213c10 {
    short field0;
    short field2;
    void* field4;
    int field8;
};

extern "C" void* func_ov031_022133f8(unsigned int flags);
extern "C" void func_ov031_02213694(void* p);

// USA: func_ov031_02213c10  (semantic: SetHandlerFlagOrDispatch_02213c10)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02213c10(S02213c10* p) {
    unsigned char* handler = (unsigned char*)func_ov031_022133f8(0x10);
    if (p->field0 == 5) {
        if (p->field2 == 0) return;
        switch (p->field8) {
        case 0xd: handler[0xd14] = 1; return;
        case 0xf: handler[0xd14] = 2; return;
        case 0x11: handler[0xd14] = 3; return;
        default: handler[0xd14] = 4; return;
        }
    } else {
        if (p->field0 != 7) return;
        func_ov031_02213694(p->field4);
    }
}
