#include <globaldefs.h>

void* GetRelativeBlockPointer020b7694(unsigned char* base);

struct BlockHolder0207eac4 {
    char pad[0x5c];
    unsigned char* block;
};

// USA: func_0207eac4
ARM void* GetBlockPointerFromField5c(struct BlockHolder0207eac4* obj) {
    unsigned char* p = obj->block;
    if (p == NULL) return NULL;
    return GetRelativeBlockPointer020b7694(p);
}
