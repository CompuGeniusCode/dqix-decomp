#include <globaldefs.h>

struct S02011ff0 {
    char pad[0x56b];
    unsigned char f : 4;
};

extern "C" struct S02011ff0* func_020108f0(void* base, int index);

// USA: func_02011ff0
ARM int GetLowNibbleAt0x56b(void* base, int index) {
    struct S02011ff0* p = func_020108f0(base, index);
    return p ? p->f : 0;
}
