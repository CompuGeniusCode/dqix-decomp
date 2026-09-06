#include <globaldefs.h>

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

extern int data_02108e78;

// USA: func_0207ba70
ARM int StoreDecodedShortAt0xa0207ba70(struct Variant02030b0c* v) {
    *(short*)(*(char**)((char*)&data_02108e78 + 4) + 0xa) = _ZNK6Script9Parameter5ToIntEv(v);
    return 1;
}
