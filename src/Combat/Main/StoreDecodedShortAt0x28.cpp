#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

extern int data_02109a28;

// USA: func_02099c90
ARM int StoreDecodedShortAt0x28(struct Variant02030b0c* arg) {
    *(short*)((char*)&data_02109a28 + 0x28) = GetIntFromVariant02030b0c(arg);
    return 1;
}
