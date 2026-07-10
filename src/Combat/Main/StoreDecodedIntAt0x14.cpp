#include <globaldefs.h>

struct Variant02030b0c;

int GetIntFromVariant02030b0c(Variant02030b0c* p);

extern int data_020fdc4c;

// USA: func_0201f844
ARM int StoreDecodedIntAt0x14(Variant02030b0c* arg) {
    int v = GetIntFromVariant02030b0c(arg);
    *(int*)(*(char**)((char*)&data_020fdc4c + 0x10) + 0x14) = v;
    return 1;
}
