#include <globaldefs.h>
#pragma optimize_for_size off

struct List020b776c {
    char pad0[7];
    unsigned char count;
    char pad8[2];
    unsigned short dataOff;
};

// USA: func_020b776c
ARM void* GetElement020b776c(struct List020b776c* list, unsigned int index) {
    if (list == NULL) {
        goto fail;
    }
    if (index >= list->count) {
        goto fail;
    }
    return (char*)list + list->dataOff + index * 0x10;
fail:
    return NULL;
}
