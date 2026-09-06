#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

struct Target02059f38;
struct Vec3_02059f38;
void CopyVec3ToField0x44(struct Target02059f38* dst, struct Vec3_02059f38* src);

struct FixedVec3_2034;
struct FixedMtx3T_2034;
extern "C" void Mat4x3_ApplyToVector(struct FixedVec3_2034* v, struct FixedMtx3T_2034* m, struct FixedVec3_2034* out);

extern "C" void* _ZN12RenderConfig20GetInverseViewMatrixEv(void);

extern "C" void _ZN8Object3D4DrawEb(void* obj, int flag);

int ForwardField4To0205765c(int* obj);

struct Vec3_02059f54 { int x; int y; int z; };

struct Flags02059f54 {
    char pad0[0xcc];
    unsigned char bit0:1;
    unsigned char bit1:1;
    unsigned char bit2:1;
    unsigned char bit3:1;
    unsigned char bit4:1;
    unsigned char bit5:1;
    unsigned char bit6:1;
    unsigned char bit7:1;
};

// USA: func_02059f54  (semantic: TransformAndSyncPosition_02059f54)
extern "C" ARM void func_02059f54(unsigned char* p, int combatantId) {
    short* fb0 = (short*)(p + 0xb0);
    if (*fb0 > 0) {
        return;
    }

    struct BattleStruct* bs = GetBattleStruct();
    if (GetCombatantUnchecked(bs, combatantId) == 0) {
        return;
    }

    struct Vec3_02059f54 origVec = *(struct Vec3_02059f54*)(p + 0x44);
    struct Flags02059f54* flags = (struct Flags02059f54*)p;

    if (flags->bit3) {
        struct Vec3_02059f54 vec = *(struct Vec3_02059f54*)(p + 0x44);
        void* m = _ZN12RenderConfig20GetInverseViewMatrixEv();
        Mat4x3_ApplyToVector((struct FixedVec3_2034*)&vec, (struct FixedMtx3T_2034*)m, (struct FixedVec3_2034*)&vec);
        CopyVec3ToField0x44((struct Target02059f38*)p, (struct Vec3_02059f38*)&vec);
    }

    if (*(int*)(p + 0xac) == 0) {
        _ZN8Object3D4DrawEb(p, flags->bit2);
    } else {
        ForwardField4To0205765c((int*)p);
    }

    if (flags->bit3) {
        CopyVec3ToField0x44((struct Target02059f38*)p, (struct Vec3_02059f38*)&origVec);
    }
}
