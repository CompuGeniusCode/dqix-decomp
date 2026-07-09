#include <globaldefs.h>
#pragma optimize_for_size off

struct VarTableHeader020b71fc {
    char pad0[5];
    unsigned char count;
    char pad6[4];
    unsigned short dataOff;
};

static inline char* GetIndexedEntry020b71fc(void* obj, unsigned int index) {
    char* base;
    char* region;
    char* elemPtr;
    struct VarTableHeader020b71fc* node;

    base = (obj != NULL && *(unsigned int*)((char*)obj + 8) != 0)
             ? (char*)obj + *(unsigned int*)((char*)obj + 8) : NULL;
    if (base == NULL) {
        goto fail;
    }
    node = (struct VarTableHeader020b71fc*)base;
    region = base + 4;
    if (region == NULL) {
        goto noelem;
    }
    if (index >= node->count) {
        goto noelem;
    }
    {
        unsigned int doff = node->dataOff;
        unsigned short stride = *(unsigned short*)(region + doff);
        elemPtr = region + doff + 4 + stride * index;
    }
    goto haveelem;
noelem:
    elemPtr = NULL;
haveelem:
    if (elemPtr != NULL) {
        return base + *(unsigned int*)elemPtr;
    }
fail:
    return NULL;
}

// USA: func_020b71fc
ARM unsigned int GetField0xcBits24To29(void* obj, unsigned int index) {
    unsigned int* entry = (unsigned int*)GetIndexedEntry020b71fc(obj, index);
    return (entry[3] & 0x3f000000) >> 24;
}
