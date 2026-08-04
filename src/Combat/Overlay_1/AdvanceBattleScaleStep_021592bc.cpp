#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

struct Vec3 { int x; int y; int z; };
void SubtractVec3(Vec3* a, Vec3* b, Vec3* out);
void AddVec3(Vec3* a, Vec3* b, Vec3* out);

struct Vec3_02030ef0;
void DivideVec3Components02030ef0(Vec3_02030ef0* src, unsigned int a, Vec3_02030ef0* dst);

struct Vec3Fixed02030e2c { int x; int y; int z; };
void ScaleVec3Fixed02030e2c(Vec3Fixed02030e2c* in, int scale, Vec3Fixed02030e2c* out);

unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);

extern "C" int func_ov001_02164578(void* table, int index, void* arg2, int arg3, float arg4);
extern "C" int func_02012fe4(void);
extern "C" int func_02018fbc(int seed, void* v);
extern void* data_ov001_02165884;

// USA: func_ov001_021592bc  (semantic: AdvanceBattleScaleStep_021592bc)
extern "C" ARM int func_ov001_021592bc(char* req, char* state) {
    int flag = 0;
    struct BattleStruct* battleStruct = GetBattleStruct();
    int fixedScale = (int)(GetBattleScaleCount(battleStruct) << 12);

    if (*(int*)(state + 0x48) >= *(int*)(req + 0x10) * 2) {
        int mode = *(int*)(req + 0x14);
        if (mode == 0) {
            memcpy(state + 0x74, req + 0x4, 0xc);
        } else if (mode == 1) {
            *(int*)(state + 0x74) = *(int*)(req + 0x4);
            *(int*)(state + 0x7c) = *(int*)(req + 0xc);
        }
        void* arg2 = req + 0x1c;
        if (arg2) {
            func_ov001_02164578(data_ov001_02165884, *(int*)(state + 0x70), arg2, flag, 0.0f);
        }
        *(int*)(state + 0x48) = 0;
        return 0;
    }

    if (*(int*)(state + 0x48) <= 0) {
        Vec3 delta;
        SubtractVec3((Vec3*)(req + 0x4), (Vec3*)(state + 0x74), &delta);
        DivideVec3Components02030ef0((Vec3_02030ef0*)&delta, (*(unsigned int*)(req + 0x10)) << 13, (Vec3_02030ef0*)(state + 0x94));
    } else {
        Vec3Fixed02030e2c tmp = *(Vec3Fixed02030e2c*)(state + 0x94);
        ScaleVec3Fixed02030e2c(&tmp, fixedScale, &tmp);
        int mode = *(int*)(req + 0x14);
        if (mode == 0) {
            AddVec3((Vec3*)(state + 0x74), (Vec3*)&tmp, (Vec3*)(state + 0x74));
        } else if (mode == 1) {
            AddVec3((Vec3*)(state + 0x74), (Vec3*)&tmp, (Vec3*)(state + 0x74));
            int seed = func_02012fe4();
            *(int*)(state + 0x78) = func_02018fbc(seed, state + 0x74);
        }
    }

    *(int*)(state + 0x48) += (int)GetBattleScaleCount(battleStruct);
    return 1;
}
