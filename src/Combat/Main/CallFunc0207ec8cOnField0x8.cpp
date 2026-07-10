#include <globaldefs.h>

struct Obj0207ec8c;
void* ClearSubEntryFlag0x40_0207ec8c(struct Obj0207ec8c*);

// USA: func_02037540
ARM void* CallFunc0207ec8cOnField0x8(void* obj) {
    void* p = *(void**)((char*)obj + 8);
    if (p == NULL) return p;
    return ClearSubEntryFlag0x40_0207ec8c((struct Obj0207ec8c*)p);
}
