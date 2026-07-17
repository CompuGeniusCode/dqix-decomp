#include <globaldefs.h>

struct Obj0RowEvent021fa298 {
    char pad0[4];
    unsigned short kind;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    char padc[4];
    int field10;
    char pad14[0x14];
    int field28;
    unsigned char field2c;
};

extern "C" void func_ov023_021f6ed8(void*);
extern "C" int func_ov023_021fa5a0(void*, int);

// USA: func_ov023_021fa298
ARM int InitEvent4_021fa298(struct Obj0RowEvent021fa298* obj, int p1, int p2, int p3, int p4, int p5, int p6) {
    func_ov023_021f6ed8(obj);
    obj->kind = 4;
    obj->field6 = p2;
    obj->field8 = p3;
    obj->fielda = 0;
    obj->field28 = p4;
    obj->field10 = p5;
    obj->field2c = p6;
    func_ov023_021fa5a0(obj, p1);
    return 1;
}
