#include <globaldefs.h>

struct S_bc7c {
    char pad[0x27d8];
    unsigned short val;
};

// USA: func_0201bc7c
ARM void SetField0x27d8(struct S_bc7c* obj, unsigned short val) {
    obj->val = val;
}
