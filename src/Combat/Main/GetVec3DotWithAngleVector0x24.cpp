#include <globaldefs.h>

struct FixedVec3 {
    int x;
    int y;
    int z;
};

int DotFixedVec3(struct FixedVec3* a, struct FixedVec3* b);
extern "C" void func_020c2f18(struct FixedVec3* src, struct FixedVec3* dst);
short GetTableEntryOdd02030c9c(int x);
short GetTableEntryEven02030c68(int x);

struct Vec3Raw020322c0 {
    unsigned int v[3];
};

struct ObjWithVec3At0x24_020322c0 {
    char pad[0x24];
    struct Vec3Raw020322c0 vec;
};

// USA: func_020322c0
ARM int GetVec3DotWithAngleVector0x24(struct ObjWithVec3At0x24_020322c0* obj, int* angle) {
    struct Vec3Raw020322c0 v2;
    struct FixedVec3 v1;
    int oddResult;
    v2 = obj->vec;
    func_020c2f18((struct FixedVec3*)&v2, (struct FixedVec3*)&v2);
    oddResult = GetTableEntryOdd02030c9c(*angle);
    v1.x = GetTableEntryEven02030c68(*angle);
    v1.y = 0;
    v1.z = oddResult;
    func_020c2f18(&v1, &v1);
    return DotFixedVec3(&v1, (struct FixedVec3*)&v2);
}
