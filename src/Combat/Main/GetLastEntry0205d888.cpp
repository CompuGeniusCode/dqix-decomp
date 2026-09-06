#include <globaldefs.h>

struct Struct0205d888 {
    char pad0[0x98];
    int field98;
    void* field9C;
    char pad1[0x14];
    unsigned char fieldB4;
};

// USA: func_0205d888
ARM void* GetLastEntry0205d888(struct Struct0205d888* p) {
    void* base;
    if (p->field98 == 0) return 0;
    base = p->field9C;
    if (base == 0) return 0;
    return p->fieldB4 != 0 ? (char*)base + (p->fieldB4 - 1) * 0xE0 : 0;
}
