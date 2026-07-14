#include <globaldefs.h>

extern "C" void func_0200f374(void* buf, int n);
short GetTableEntryEven02030c68(int x);
short GetTableEntryOdd02030c9c(int x);

struct Vec3 { int x; int y; int z; };
struct Vec3Fixed02030e2c { int x; int y; int z; };
void ScaleVec3Fixed02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);
void AddVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);

struct Vec3Fixed02037c80 { int x; int y; int z; };

struct Obj02037c80 {
    char pad[0x44];
    Vec3Fixed02037c80 fieldA;
    Vec3Fixed02037c80 fieldB;
};

// USA: func_02037c80
ARM struct Vec3Fixed02037c80 ComputeOffsetVec02037c80(struct Obj02037c80* obj, int scale) {
    Vec3Fixed02037c80 fieldA = obj->fieldA;
    Vec3Fixed02037c80 fieldB = obj->fieldB;
    Vec3Fixed02037c80 fieldC;
    func_0200f374(&fieldC, 0xc);
    fieldC.x = GetTableEntryEven02030c68(fieldB.y);
    fieldC.z = GetTableEntryOdd02030c9c(fieldB.y);
    Vec3Fixed02037c80 scaled;
    ScaleVec3Fixed02030e2c((Vec3Fixed02030e2c*)&fieldC, scale, (Vec3Fixed02030e2c*)&scaled);
    AddVec3((Vec3*)&scaled, (Vec3*)&fieldA, (Vec3*)&scaled);
    return scaled;
}
