#include <globaldefs.h>

struct Obj020553ac {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    char sub14[0xc0 - 0x14];
    char subc0[0x1e8 - 0xc0];
    int field1e8;
    int field1ec;
};

extern "C" void func_02034bc4(void* obj);
extern "C" void func_02054f80(void* obj);

// USA: func_020553ac
ARM void InitStruct020553ac(struct Obj020553ac* obj) {
    obj->field0 = -1;
    obj->field1ec = 0;
    obj->field4 = 0;
    obj->field8 = 0;
    obj->fieldc = 0;
    obj->field10 = 0;
    obj->field1e8 = 0;
    func_02034bc4(&obj->sub14);
    func_02054f80(&obj->subc0);
}
