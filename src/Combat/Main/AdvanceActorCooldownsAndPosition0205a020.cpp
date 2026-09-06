#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Vec3 { int x; int y; int z; };
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);

struct Vec3Fixed02030e2c { int x; int y; int z; };
extern "C" void func_02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

struct Target02059f38;
struct Vec3_02059f38;
void CopyVec3ToField0x44(struct Target02059f38* dst, struct Vec3_02059f38* src);

extern "C" void _ZN8Object3D14AdvanceEffectsEv(void* obj);

struct BitFlags02037170;
extern "C" int _ZNK8Object3D19HasAnimationStoppedEv(struct BitFlags02037170* obj);

void InitStruct02059cc8(unsigned char* obj);

struct ListNode02057854;
int CheckListStableAndField8LtField402057854(struct ListNode02057854* node);

int ForwardField4To02057334(int* obj);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

extern int data_02108760;

// USA: func_0205a020
ARM void AdvanceActorCooldownsAndPosition0205a020(unsigned char* p, int dt) {
    GetBattleStruct();

    short* timerB0 = (short*)(p + 0xb0);
    if (*timerB0 > 0) {
        *timerB0 -= dt;
        return;
    }

    if (*(int*)(p + 0xac) == 0) {
        if (*(int*)(p + 0xb8) > 0) {
            int f28 = *(int*)(p + 0x28);
            int fbc = *(int*)(p + 0xbc);
            if (f28 <= fbc) {
                int f24 = *(int*)(p + 0x24);
                if (fbc < f24) {
                    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, *(int*)(p + 0xb8), 0);
                }
            }
        }

        struct PosHolder0205a020 { char pad[0x44]; struct Vec3 pos; };
        struct Vec3 pos = ((struct PosHolder0205a020*)p)->pos;

        struct Vec3 vel;
        func_02030e2c((struct Vec3Fixed02030e2c*)(p + 0xc0), dt << 12, (struct Vec3Fixed02030e2c*)&vel);
        Vector3fix_Add(&pos, &vel, &pos);
        CopyVec3ToField0x44((struct Target02059f38*)p, (struct Vec3_02059f38*)&pos);

        _ZN8Object3D14AdvanceEffectsEv(p);

        if (p[0x19] & 1) {
            if (_ZNK8Object3D19HasAnimationStoppedEv((struct BitFlags02037170*)p)) {
                InitStruct02059cc8(p);
            }
        }

        short* timerB6 = (short*)(p + 0xb6);
        if (*timerB6 > 0) {
            *timerB6 -= dt;
            if (*timerB6 <= 0) {
                InitStruct02059cc8(p);
            }
        }
    } else {
        if (CheckListStableAndField8LtField402057854(*(struct ListNode02057854**)(p + 0x4)) == 1) {
            InitStruct02059cc8(p);
        } else {
            ForwardField4To02057334((int*)p);
        }
    }
}
