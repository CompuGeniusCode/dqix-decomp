#include <globaldefs.h>

struct Variant02030b0c { int tag; int val; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
extern int data_02109404;

// USA: func_020954b0
ARM int StoreByteToTable02109404(struct Variant02030b0c* args) {
    unsigned char val = _ZNK6Script9Parameter5ToIntEv(args);
    unsigned char idx = _ZNK6Script9Parameter5ToIntEv(args + 1);
    if (idx < 0xcc) {
        unsigned char* base = *(unsigned char**)((char*)&data_02109404 + 0x10);
        base[idx] = val;
    }
    return 1;
}
