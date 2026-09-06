#include <globaldefs.h>
#include "System/Memory.h"

struct Entry020e2cc4;
void SetEntryEnabled020e2cc4(struct Entry020e2cc4*, int);
struct Entry020e2c7c;
void DispatchEntryHandlers020e2c7c(struct Entry020e2c7c*);

struct Struct_020e2bd8 {
    unsigned char field0;
    unsigned char field1;
    unsigned char field2;
    unsigned char pad3;
    int field4;
    int field8;
    int fieldc;
    int field10;
    unsigned char field14[0x10];
};

// USA: func_020e2bd8
ARM void Init020e2bd8(struct Struct_020e2bd8* obj, int arg1, int arg2) {
    obj->field0 = 0;
    obj->field1 = arg1;
    obj->field2 = arg2;
    VectorizedMemset(obj->field14, 0, 0x10);
    obj->field4 = 5;
    obj->field8 = 1;
    obj->fieldc = 0x1f;
    obj->field10 = 1;
    SetEntryEnabled020e2cc4((struct Entry020e2cc4*)obj, 0);
    DispatchEntryHandlers020e2c7c((struct Entry020e2c7c*)obj);
}
