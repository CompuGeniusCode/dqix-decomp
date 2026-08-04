#include <globaldefs.h>

struct Obj021fa03c;
struct Elem021fa03c;
Elem021fa03c* FindFreeSlot_021fa03c(Obj021fa03c*);
struct Obj021f9eb4;
void ClearFields0To3_021f9eb4(Obj021f9eb4*);
extern "C" void* func_ov011_021849c8(void*);

struct Vec3_021fa078 { int x, y, z; };

class VNode021fa078 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual Vec3_021fa078 MethodAt20();
};

extern "C" VNode021fa078* func_ov023_021f6880(void*, int);
void CopyVec3(int*, int*);

struct Slot021fa078 {
    unsigned short field0;
    unsigned char field2;
    unsigned char field3;
    int field4;
    int field8;
    int fieldc;
    int field10[3];
    int field1c[3];
};

// USA: func_ov023_021fa078  (semantic: CreateAndInitSlot_021fa078)
extern "C" ARM void func_ov023_021fa078(Obj021fa03c* obj, void* ctx, unsigned short val, int* srcVec, int p5, int p6) {
    Slot021fa078* slot = (Slot021fa078*)FindFreeSlot_021fa03c(obj);
    if (slot == NULL) return;
    ClearFields0To3_021f9eb4((Obj021f9eb4*)slot);
    slot->field2 = 1;
    slot->field0 = val;
    void* base = func_ov011_021849c8(ctx);
    VNode021fa078* node = func_ov023_021f6880(base, slot->field0);
    if (node == NULL) return;
    slot->field4 = 0;
    slot->field8 = p6;
    slot->fieldc = p5;
    const Vec3_021fa078& v = node->MethodAt20();
    CopyVec3(slot->field10, (int*)&v);
    CopyVec3(slot->field1c, srcVec);
}
