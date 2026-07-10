#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
extern void* data_02108efc;

// USA: func_020899dc
ARM int SetGlobalShortField10(struct Variant02030b0c* p) {
    *(short*)((char*)data_02108efc + 0x10) = GetIntFromVariant02030b0c(p);
    return 1;
}
