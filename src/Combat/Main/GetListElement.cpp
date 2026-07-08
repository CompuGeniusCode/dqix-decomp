#include <globaldefs.h>

struct List_b780c {
    char pad0[0xc];
    unsigned char unkC;
    unsigned char count;
    char padE[4];
    unsigned short dataOff;
};

// USA: func_020b780c
ARM void* GetListElement(struct List_b780c* list, unsigned int index) {
    char* region = (char*)list + 0xc;
    unsigned short off;
    unsigned short stride;
    if (region == NULL) {
        goto fail;
    }
    if (index >= list->count) {
        goto fail;
    }
    off = list->dataOff;
    stride = *(unsigned short*)(region + off);
    return region + off + 4 + stride * index;
fail:
    return NULL;
}
