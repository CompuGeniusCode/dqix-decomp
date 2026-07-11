#include <globaldefs.h>

extern "C" void func_020ca3ec(int fill, void* dst, int size);
extern int data_020f1c84;
extern int data_020f1c88;
extern int data_020f1c8c;

struct Struct020b2b6c {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
    int field1c;
    int rest[14];
};

// USA: func_020b2b6c
ARM void InitStruct020b2b6c(struct Struct020b2b6c* dst, int arg1) {
    func_020ca3ec(0, dst, 0x54);
    dst->fieldc = data_020f1c8c;
    dst->field14 = data_020f1c88;
    dst->field1c = data_020f1c84;
    dst->field4 = arg1;
}
