#include <globaldefs.h>

extern int data_0210782c[];

// USA: func_020425b4
ARM void* GetBoundedEntry020425b4(int idx, int tableIdx) {
    char* t = (char*)data_0210782c[tableIdx];
    if (idx >= 0 && (unsigned int)idx < *(unsigned int*)(t + 0x4))
        return (void*)(*(int*)(t + 0x10) + (idx << 3));
    return NULL;
}
