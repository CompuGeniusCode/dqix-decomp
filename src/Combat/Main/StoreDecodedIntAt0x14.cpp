#include <globaldefs.h>

struct Variant02030b0c;

extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c* p);

extern int data_020fdc4c;

// USA: func_0201f844
ARM int StoreDecodedIntAt0x14(Variant02030b0c* arg) {
    int v = _ZNK6Script9Parameter5ToIntEv(arg);
    *(int*)(*(char**)((char*)&data_020fdc4c + 0x10) + 0x14) = v;
    return 1;
}
