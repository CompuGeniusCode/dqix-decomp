#include <globaldefs.h>

// USA: func_ov023_021d994c
ARM void* Find_021d994c(void* obj, int key) {
    char* entry = *(char**)((char*)obj + 0x120);
    int i = 0;
    while (i < *(unsigned char*)((char*)obj + 0x11e)) {
        if (*(unsigned char*)entry == key) {
            return entry;
        }
        i++;
        entry += 0x99c;
    }
    return NULL;
}
