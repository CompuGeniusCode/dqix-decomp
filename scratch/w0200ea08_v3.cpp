#include <globaldefs.h>

extern "C" void func_0200df80(void* a, void* b, int c, int d);
extern "C" void func_0200f2ec(void* a, void* b, int c);

struct ObjA0200ea08 {
    int field0;
    int field4;
    int field8;
    unsigned char pad[0x18 - 0xc];
    int field18;
};
struct ObjB0200ea08 {
    int field0;
};
struct ObjC0200ea08 {
    unsigned char pad[0x4];
    int field4;
    int field8;
};

// USA: func_0200ea08
ARM void RegisterFields0200ea08(struct ObjA0200ea08* a, struct ObjB0200ea08* b, struct ObjC0200ea08* c, int d) {
    func_0200df80(a, b, d, d);
    int* dest = (int*)(a->field18 + c->field8);
    dest[0] = a->field4;
    dest[1] = a->field0;
    dest[2] = a->field8;
    *(int*)((char*)dest + 0x14) = d;
    func_0200f2ec(a, b, b->field0 + c->field4);
}
