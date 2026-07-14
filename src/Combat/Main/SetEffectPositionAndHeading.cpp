#include <globaldefs.h>
void* ConvertTaggedVec3ToFx32(struct TaggedValue02030b44*, int*);

struct TaggedValue02030b44 {
    int type;
    union { int i; float f; } value;
};
float GetTaggedValueAsFloat(struct TaggedValue02030b44* v);
extern "C" short func_02030f30(int);
void CopyVec3(int* dst, int* src);

struct Global020fdc20_d494 {
    int pad0;
    int pad4;
    unsigned char* obj; // 0x8
};
extern struct Global020fdc20_d494 data_020fdc20;

// USA: func_0201d494
ARM int SetEffectPositionAndHeading(void* arg0) {
    int vec[3];
    struct TaggedValue02030b44* v = (struct TaggedValue02030b44*)ConvertTaggedVec3ToFx32((struct TaggedValue02030b44*)(arg0), (int*)(vec));
    float f = GetTaggedValueAsFloat(v);
    int angle = (int)(4096.0f * f);
    short heading = func_02030f30(angle);
    unsigned char* obj = data_020fdc20.obj;
    CopyVec3((int*)(obj + 0x70), vec);
    *(short*)(obj + 0x7c) = heading;
    return 1;
}
