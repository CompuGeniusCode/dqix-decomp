#include <globaldefs.h>

struct Obj0RowEvent {
    char pad0[4];
    unsigned short kind;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    char padc[4];
    int field10;
    char pad14[0xc];
    int field20;
    int field24;
    unsigned char field28;
    unsigned char field29;
};

struct Pair021fd1e0 { int a, b; };
struct BytePair021fd1e0 { unsigned char a, b; };

extern "C" void func_ov023_021f6ed8(void*);

// USA: func_ov023_021fd1e0
ARM int InitEventD_021fd1e0(struct Obj0RowEvent* obj, int unused, int p2, int p3, struct Pair021fd1e0* p4, struct BytePair021fd1e0* p5) {
    func_ov023_021f6ed8(obj);
    obj->kind = 0xd;
    obj->field6 = p2;
    obj->field8 = p3;
    obj->field20 = p4->a;
    obj->field24 = p4->b;
    obj->field28 = p5->a;
    obj->field29 = p5->b;
    return 1;
}
