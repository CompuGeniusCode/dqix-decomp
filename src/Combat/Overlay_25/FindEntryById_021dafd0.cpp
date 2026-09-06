#include <globaldefs.h>

// USA: func_ov025_021dafd0
ARM void* FindEntryById_021dafd0(char* obj, int id) {
    int flag;
    if (id < 0) goto zero;
    if (id <= 3) { flag = 1; goto check; }
zero:
    flag = 0;
check:
    if (flag == 0) goto fail;
    for (int i = 0; i < 4; i++) {
        int val = *(int*)(obj + i * 0x448 + 0x9a4);
        if (id == val) {
            return obj + 0x958 + i * 0x448;
        }
    }
fail:
    return NULL;
}
