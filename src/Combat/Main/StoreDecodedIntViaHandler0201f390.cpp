#include <globaldefs.h>

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c* p);
extern "C" void func_02027b10(void* obj, int value);
extern int data_020fdc4c;

// USA: func_0201f390
ARM int StoreDecodedIntViaHandler0201f390(Variant02030b0c* arg) {
    int value = _ZNK6Script9Parameter5ToIntEv(arg);
    func_02027b10(*(char**)((char*)&data_020fdc4c + 0x10), value);
    return 1;
}
