#include <globaldefs.h>

struct Variant02030b0c { int tag; union { int i; float f; } u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c* p);
extern int data_020fdc4c;

// USA: func_0201f4cc
ARM int StoreTwoDecodedIntsAt0x18(Variant02030b0c* args) {
    int v1 = _ZNK6Script9Parameter5ToIntEv(args);
    int v2 = _ZNK6Script9Parameter5ToIntEv(args + 1);
    char* obj = *(char**)((char*)&data_020fdc4c + 0x10);
    *(int*)(obj + 0x18) = v1;
    *(int*)(obj + 0x1c) = v2;
    return 1;
}
