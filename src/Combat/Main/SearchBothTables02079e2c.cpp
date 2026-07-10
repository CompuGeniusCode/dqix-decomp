#include <globaldefs.h>

struct Obj02079e60;
typedef int (*CmpFn02079e60)(void*);
void* BinarySearchByComparator02079e60(struct Obj02079e60* obj, int key, CmpFn02079e60 cmp);

struct S020797e8;
int GetLow12BitsAt0x4(struct S020797e8* p);

// USA: func_02079e2c
ARM void* SearchBothTables02079e2c(char* p, int key) {
    void* r = BinarySearchByComparator02079e60((struct Obj02079e60*)p, key, (CmpFn02079e60)GetLow12BitsAt0x4);
    if (r != 0) return r;
    return BinarySearchByComparator02079e60((struct Obj02079e60*)(p + 0xc), key, (CmpFn02079e60)GetLow12BitsAt0x4);
}
