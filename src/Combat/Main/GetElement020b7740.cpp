#include <globaldefs.h>
#pragma optimize_for_size off

struct List020b7740 {
    char pad0[6];
    unsigned char count;
    char pad7;
    unsigned short dataOff;
};

// USA: func_020b7740
ARM void* GetElement020b7740(struct List020b7740* list, unsigned int index) {
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
