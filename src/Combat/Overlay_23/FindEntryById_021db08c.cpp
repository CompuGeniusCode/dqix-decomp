#include <globaldefs.h>

struct Entry021db08c { short id; char pad[6]; };

// USA: func_ov023_021db08c
ARM void* FindEntryById_021db08c(void* obj, int val) {
    int i;
    if (val < 0) return NULL;
    for (i = 0; i < *(unsigned short*)((char*)obj + 6); i++) {
        struct Entry021db08c* list = *(struct Entry021db08c**)obj;
        if (list[i].id == val) return &list[i];
    }
    return NULL;
}
