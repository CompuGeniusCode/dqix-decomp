#include <globaldefs.h>

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

extern int data_02109a28;

// USA: func_02099c90
ARM int StoreDecodedShortAt0x28(struct Variant02030b0c* arg) {
    *(short*)((char*)&data_02109a28 + 0x28) = _ZNK6Script9Parameter5ToIntEv(arg);
    return 1;
}
