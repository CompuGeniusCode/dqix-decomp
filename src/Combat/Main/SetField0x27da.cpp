#include <globaldefs.h>

struct S_bc88 {
    char pad[0x27da];
    unsigned short val;
};

// USA: func_0201bc88
ARM void SetField0x27da(struct S_bc88* obj, unsigned short val) {
    obj->val = val;
}
