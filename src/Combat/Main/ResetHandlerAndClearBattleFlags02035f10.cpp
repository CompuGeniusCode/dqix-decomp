#include <globaldefs.h>

extern "C" void func_02034d20(void*);
extern "C" void func_02035554(void*, int, unsigned int);
extern "C" void func_0200f374(void*, int);
extern "C" void func_020c1280(void*, int, int);
extern "C" void func_0207e87c(void*, int);

struct Vec3Block020b3850 { unsigned int v[3]; };
void StoreVec3AndClearFlags020b3850(struct Vec3Block020b3850* src);

short GetTableEntryOdd02030c9c(int x);
short GetTableEntryEven02030c68(int x);

void ClearGlobalFlagBits02016d8c(void* arg0);

struct Vec3Block020b3880 { unsigned int v[3]; };
void StoreVec3AndClearFlags020b3880(struct Vec3Block020b3880* src);

void InvokeHandlerAndClearFlags020b3814(void);

extern struct Vec3Block020b3880 data_020e7800;

struct FieldBlock02104b18_02035f10 {
    unsigned char pad[0x14];
    unsigned int field0x14;
};
extern struct FieldBlock02104b18_02035f10 data_02104b18;

struct Obj02035f10 {
    unsigned char pad0[0x8];
    void* field0x8;
    unsigned char pad1[0x48];
    int field0x54;
    unsigned char pad2[0x14];
    unsigned int field0x6c;
    unsigned char pad3[0x38];
    unsigned int field0xa8;
};

// USA: func_02035f10
ARM void ResetHandlerAndClearBattleFlags02035f10(struct Obj02035f10* obj) {
    if (obj->field0x8 == NULL) return;

    obj->field0x6c &= ~0x20;
    func_02034d20(obj);

    obj->field0x6c |= 0x20;
    func_02035554(obj, 0, obj->field0x6c);

    struct Vec3Block020b3850 buf;
    func_0200f374(&buf, sizeof(buf));
    StoreVec3AndClearFlags020b3850(&buf);

    int a = GetTableEntryOdd02030c9c(obj->field0x54);
    int b = GetTableEntryEven02030c68(obj->field0x54);
    int buf2[9];
    func_020c1280(buf2, b, a);
    ClearGlobalFlagBits02016d8c(buf2);

    struct Vec3Block020b3880 buf3 = data_020e7800;
    StoreVec3AndClearFlags020b3880(&buf3);

    InvokeHandlerAndClearFlags020b3814();

    data_02104b18.field0x14 = obj->field0xa8;
    func_0207e87c(obj->field0x8, 0);

    data_02104b18.field0x14 = 0;
}
