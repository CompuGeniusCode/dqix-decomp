#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
extern void* data_02108efc;

// USA: func_02089aa0
ARM int SetGlobalShortField18(struct Variant02030b0c* p) {
    *(short*)((char*)data_02108efc + 0x18) = GetIntFromVariant02030b0c(p);
    return 1;
}
