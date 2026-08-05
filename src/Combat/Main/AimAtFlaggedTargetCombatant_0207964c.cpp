#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
int GetField0x17dBits4To5IfFlag8(unsigned char* obj);
int GetIntAt0x64(unsigned char* obj);
void CopyVec3(int* dst, int* src);
extern "C" int func_02030f30(int arg);
struct Obj02033874;
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);

struct Vec3Fixed02037c80 { int x; int y; int z; };
struct Obj02037c80;
struct Vec3Fixed02037c80 ComputeOffsetVec02037c80(struct Obj02037c80* obj, int scale);

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
                int scale = GetIntAt0x64(combatant) / 4 + GetIntAt0x64(self) / 2;
                struct Vec3Fixed02037c80 vec = ComputeOffsetVec02037c80((struct Obj02037c80*)combatant, scale);
                int angleArg = *(int*)(combatant + 0x54) + 0x3244;
                int aim = func_02030f30(angleArg);
                CopyVec3((int*)(self + 0x44), (int*)&vec);
                SetVecYFromValue02033874((struct Obj02033874*)self, aim);
            }
        }
    }
}
