#include <globaldefs.h>

struct Variant02030b0c { int tag; union { int i; float f; } u; };
extern int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
extern struct TaggedValue02030b44* ConvertTaggedVec3ToFx32(struct TaggedValue02030b44* obj, int* outVec);
extern float GetTaggedValueAsFloat(struct TaggedValue02030b44* v);

extern void CopyVec3(int* dst, int* src);
extern void ResetStruct0201d424(char* obj);
extern "C" int func_02030f30(int value);

struct RecordArray0201e710 { char pad[0x24]; void* items; int count; int capacity; };
extern "C" void* func_0201e710(struct RecordArray0201e710* arr, void* src);

static inline int FixedMulRound0201d530(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

struct Record0201d530 {
    short f0;
    int f4;
    int vecA[3];
    int vecB[3];
    short f20;
    short f22;
    int f24;
    char pad28[0x74 - 0x28];
};

struct GlobalCtx0201d530 {
    void* lastEntry;
    int pad4;
    struct RecordArray0201e710* arr;
};
extern struct GlobalCtx0201d530 data_020fdc20;

// USA: func_0201d530
extern "C" ARM int func_0201d530(struct Variant02030b0c* param0) {
    struct Record0201d530 rec;
    int tmp[3];

    ResetStruct0201d424((char*)&rec);
    rec.f4 = GetIntFromVariant02030b0c(param0);

    struct TaggedValue02030b44* next = ConvertTaggedVec3ToFx32((struct TaggedValue02030b44*)((char*)param0 + 8), tmp);
    CopyVec3(rec.vecA, tmp);

    next = ConvertTaggedVec3ToFx32(next, tmp);
    CopyVec3(rec.vecB, tmp);

    rec.f22 = (short)func_02030f30((int)(4096.0f * GetTaggedValueAsFloat(next)));
    rec.f20 = (short)(int)(4096.0f * GetTaggedValueAsFloat((struct TaggedValue02030b44*)((char*)next + 8)));

    int halfX = rec.vecB[0] / 2;
    int halfZ = rec.vecB[2] / 2;
    int qz = FixedMulRound0201d530(halfZ, halfZ);
    int qx = FixedMulRound0201d530(halfX, halfX);
    rec.f24 = qx + qz;

    data_020fdc20.lastEntry = func_0201e710(data_020fdc20.arr, &rec);
    return 1;
}
