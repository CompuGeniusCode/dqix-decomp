#include <globaldefs.h>

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
extern void* data_02108efc;

// USA: func_020899dc
ARM int SetGlobalShortField10(struct Variant02030b0c* p) {
    *(short*)((char*)data_02108efc + 0x10) = _ZNK6Script9Parameter5ToIntEv(p);
    return 1;
}
