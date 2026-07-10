#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct Obj020899bc {
    char pad[8];
    short field8;
};

extern struct Obj020899bc* data_02108efc;

// USA: func_020899bc
ARM int StoreVariantToGlobalField8(struct Variant02030b0c* p) {
    data_02108efc->field8 = (short)GetIntFromVariant02030b0c(p);
    return 1;
}
