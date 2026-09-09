#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
int GetField0x17dBits4To5IfFlag8(unsigned char* obj);
extern "C" int _ZNK8Object3D9GetRadiusEv(unsigned char* obj);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int arg);
struct Obj02033874;
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);

struct Vec3Fixed02037c80 { int x; int y; int z; };
struct Obj02037c80;
extern "C" struct Vec3Fixed02037c80 _ZNK8Object3D15GetPointInFrontEi(struct Obj02037c80* obj, int scale);

struct CombatantFlagObj0207964c {
    char pad[0xc1];
    unsigned char flags2 : 2;
};

// USA: func_0207964c  (semantic: AimAtFlaggedTargetCombatant_0207964c)
extern "C" ARM void func_0207964c(unsigned char* self) {
    if (self[0x17d] & 8) {
        struct BattleStruct* battleStruct = GetBattleStruct();
        int field = GetField0x17dBits4To5IfFlag8(self);
        unsigned char* combatant = (unsigned char*)GetCombatantWithFlag0x800(battleStruct, field);
        if (combatant != NULL) {
            if (!(((struct CombatantFlagObj0207964c*)combatant)->flags2 & 1)) {
                int scale = _ZNK8Object3D9GetRadiusEv(combatant) / 4 + _ZNK8Object3D9GetRadiusEv(self) / 2;
                struct Vec3Fixed02037c80 vec = _ZNK8Object3D15GetPointInFrontEi((struct Obj02037c80*)combatant, scale);
                int angleArg = *(int*)(combatant + 0x54) + 0x3244;
                int aim = _Z22fix32ReduceAngle0To2Pii(angleArg);
                _ZN8Vector3iaSERKS_((int*)(self + 0x44), (int*)&vec);
                SetVecYFromValue02033874((struct Obj02033874*)self, aim);
            }
        }
    }
}
