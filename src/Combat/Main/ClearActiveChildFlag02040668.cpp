#include <globaldefs.h>

void ClearFlag0x1InField0x6c(unsigned char* obj);

struct Node02040668 {
    char pad[0x14];
    void* f14;
    void* f18;
    void* f1c;
};

// USA: func_02040668
ARM void ClearActiveChildFlag02040668(struct Node02040668* obj) {
    if (obj->f14 != NULL) {
        *(unsigned int*)((char*)obj->f14 + 0x50) &= ~1;
        return;
    }
    if (obj->f18 != NULL) {
        ClearFlag0x1InField0x6c((unsigned char*)obj->f18);
        return;
    }
    if (obj->f1c != NULL) {
        ClearFlag0x1InField0x6c((unsigned char*)obj->f1c);
    }
}
