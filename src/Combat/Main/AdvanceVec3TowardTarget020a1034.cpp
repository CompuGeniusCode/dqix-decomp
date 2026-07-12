#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Vec3_02030ef0 {
    int x;
    int y;
    int z;
};

void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
void AddVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
int Vec3LengthRounded(int* v);
void CopyVec3(int* dst, int* src);
void DivideVec3Components02030ef0(struct Vec3_02030ef0* src, unsigned int a, struct Vec3_02030ef0* dst);

struct MoveState020a1034 {
    int flag_0x0;
    struct Vec3 pos_0x4;
    struct Vec3 target_0x10;
    char unk_1c[0x8];
    int steps_0x24;
};

// USA: func_020a1034
ARM void AdvanceVec3TowardTarget020a1034(struct MoveState020a1034* obj) {
    struct Vec3 diff;
    SubtractVec3(&obj->target_0x10, &obj->pos_0x4, &diff);
    if (Vec3LengthRounded((int*)&diff) < 0x199) {
        CopyVec3((int*)&obj->pos_0x4, (int*)&obj->target_0x10);
        obj->flag_0x0 = 0;
    } else {
        struct Vec3 quotient;
        DivideVec3Components02030ef0((struct Vec3_02030ef0*)&diff, obj->steps_0x24, (struct Vec3_02030ef0*)&quotient);
        AddVec3(&obj->pos_0x4, &quotient, &obj->pos_0x4);
    }
}
