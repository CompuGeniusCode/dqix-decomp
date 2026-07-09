#include <globaldefs.h>
#pragma optimize_for_size off

struct VarTableHeader020b700c {
    char pad0[5];
    unsigned char count;
    char pad6[4];
    unsigned short dataOff;
};

static inline char* GetIndexedEntry020b700c(void* obj, unsigned int index) {
    char* base;
    char* region;
    char* elemPtr;
    struct VarTableHeader020b700c* node;

    base = (obj != NULL && *(unsigned int*)((char*)obj + 8) != 0)
             ? (char*)obj + *(unsigned int*)((char*)obj + 8) : NULL;
    if (base == NULL) {
        goto fail;
    }
    node = (struct VarTableHeader020b700c*)base;
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

// USA: func_020b700c
ARM void SetField0x4Low15Bits(void* obj, unsigned int index, unsigned int value) {
    unsigned int* entry = (unsigned int*)GetIndexedEntry020b700c(obj, index);
    entry[1] = (entry[1] & -0x8000) | value;
}
