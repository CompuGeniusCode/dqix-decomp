#include <globaldefs.h>

extern "C" void _ZN8Vector3iaSERKS_(int*, int*);

struct Entity020AE398 {
    char pad0[0x44];
    int vec44[3];         // 0x44
    char pad1[0x168 - 0x44 - 12];
    int field168;         // 0x168
    char pad2[0x178 - 0x168 - 4];
    int field178;         // 0x178
};

// USA: func_020ae398
ARM void SubtractHeightOffset020ae398(struct Entity020AE398* obj) {
    int local[3];
    _ZN8Vector3iaSERKS_(local, obj->vec44);
    local[1] -= 0x199;
    _ZN8Vector3iaSERKS_(obj->vec44, local);
    obj->field168 -= 0x199;
    obj->field178 -= 0x199;
}
