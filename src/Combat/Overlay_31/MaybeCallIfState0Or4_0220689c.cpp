#include <globaldefs.h>

extern "C" void func_ov031_022033e8(void);

struct Struct0220689c { char pad[0x73]; signed char field73; };

// USA: func_ov031_0220689c
ARM int MaybeCallIfState0Or4_0220689c(void* obj) {
    struct Struct0220689c* p = *(struct Struct0220689c**)((char*)obj + 4);
    int shouldCall = 1;
    signed char v = p->field73;
    if (v != 0 && v != 4) {
        shouldCall = 0;
    }
    if (shouldCall) {
        func_ov031_022033e8();
    }
    return 0;
}
