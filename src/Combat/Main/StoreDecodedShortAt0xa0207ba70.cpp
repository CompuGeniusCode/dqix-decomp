#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

extern int data_02108e78;

// USA: func_0207ba70
ARM int StoreDecodedShortAt0xa0207ba70(struct Variant02030b0c* v) {
    *(short*)(*(char**)((char*)&data_02108e78 + 4) + 0xa) = GetIntFromVariant02030b0c(v);
    return 1;
}
