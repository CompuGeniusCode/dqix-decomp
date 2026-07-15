#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Vec3_020a0e4c { int x; int y; int z; };
struct Vec3s32_020c3030_020a0e4c { int x; int y; int z; };

int GetField0x3b4Value(struct BattleStruct* battleStruct);
void SubtractVec3(struct Vec3_020a0e4c* a, struct Vec3_020a0e4c* b, struct Vec3_020a0e4c* out);
void AddVec3(struct Vec3_020a0e4c* a, struct Vec3_020a0e4c* b, struct Vec3_020a0e4c* out);
void CopyVec3(int* dst, int* src);
extern "C" void func_020c2f18(struct Vec3_020a0e4c* a, struct Vec3_020a0e4c* b);
int Distance3D020c3030(struct Vec3s32_020c3030_020a0e4c* a, struct Vec3s32_020c3030_020a0e4c* b);
void ScaleVec3Fixed02030e2c(struct Vec3_020a0e4c* in, int scale, struct Vec3_020a0e4c* out);

struct ArcMoveState020a0e4c {
    int flag_0x0;
    struct Vec3_020a0e4c pos_0x4;
    struct Vec3_020a0e4c target_0x10;
    int vy_0x1c;
    int vyMax_0x20;
    int steps_0x24;
};

// USA: func_020a0e4c
ARM void AdvanceVec3AlongArcTowardTarget020a0e4c(struct ArcMoveState020a0e4c* obj) {
    float ratio = (float)(unsigned int)GetField0x3b4Value(GetBattleStruct()) / 1000.0f;
    int scaledSteps = (int)((float)obj->steps_0x24 * ratio);
    int scaledVy = (int)((float)obj->vy_0x1c * ratio);

    struct Vec3_020a0e4c diff;
    SubtractVec3(&obj->target_0x10, &obj->pos_0x4, &diff);
    func_020c2f18(&diff, &diff);
    int dist = Distance3D020c3030((struct Vec3s32_020c3030_020a0e4c*)&obj->target_0x10, (struct Vec3s32_020c3030_020a0e4c*)&obj->pos_0x4);

    float v5f = (float)scaledVy / 4096.0f;
    float sq = v5f * v5f;
    float v7f = (float)scaledSteps / 4096.0f;
    float peak = sq / (2.0f * v7f);

    if (dist < scaledSteps) {
        CopyVec3((int*)&obj->pos_0x4, (int*)&obj->target_0x10);
        obj->flag_0x0 = 0;
        return;
    }

    int t = (int)(peak * 4096.0f);
    if (t < dist + 0x199) {
        int scale = scaledVy + scaledSteps;
        int newVal = (int)((float)scale / ratio);
        obj->vy_0x1c = newVal;
        int vyMax = obj->vyMax_0x20;
        if (vyMax < newVal) {
            obj->vy_0x1c = vyMax;
            scale = (int)((float)vyMax * ratio);
        }
        struct Vec3_020a0e4c scaled;
        ScaleVec3Fixed02030e2c(&diff, scale, &scaled);
        AddVec3(&obj->pos_0x4, &scaled, &obj->pos_0x4);
        return;
    }

    int diffRV = scaledVy - scaledSteps;
    int half = dist / 2;
    int clamped = diffRV;
    if (diffRV > half) clamped = half;
    obj->vy_0x1c = (int)((float)clamped / ratio);
    if (clamped < scaledSteps) {
        CopyVec3((int*)&obj->pos_0x4, (int*)&obj->target_0x10);
        obj->flag_0x0 = 0;
        return;
    }
    struct Vec3_020a0e4c scaled2;
    ScaleVec3Fixed02030e2c(&diff, clamped, &scaled2);
    AddVec3(&obj->pos_0x4, &scaled2, &obj->pos_0x4);
}
