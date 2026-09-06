#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_02012fe4(void);
extern "C" int func_02030f30(int angle);
extern "C" void func_020399b0(struct CombatantStruct* combatant, unsigned short arg1, int* vec3, int value);
extern "C" int func_ov017_0218b5b0(void);

void* GetField0x3f8Address(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
unsigned char GetByte0x26c(char* obj);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

struct Owner_1e80c;
struct S_e820;
struct ThreeWords_1e80c { int field0; int field4; int field8; };
ThreeWords_1e80c GetThreeWordsAt0x70(Owner_1e80c* src);
int GetSignedFieldAt0x7c(S_e820* p);

// USA: func_ov017_0219c598  (semantic: DispatchVec3EventToFlaggedCombatants_0219c598)
extern "C" ARM void func_ov017_0219c598(int* srcVec3, short* srcAngle, int forceFlag) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    unsigned char* field3f8 = (unsigned char*)GetField0x3f8Address(battleStruct);
    void* dataBase = func_02012fe4();
    func_ov017_0218b5b0();
    unsigned char* field2a04 = (unsigned char*)GetPtrField0x2a04(battleStruct);
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battleStruct);

    if (field3f8[0xa] != 0 && forceFlag == 0) {
        return;
    }
    if (field3f8[0x67] != 0 && GetByte0x26c((char*)combatant) != 0) {
        return;
    }

    int vec3[3];
    int angle;
    int i;
    if (srcVec3 != 0) {
        _ZN8Vector3iaSERKS_(vec3, srcVec3);
        if (srcAngle != 0) {
            angle = *srcAngle;
        }
    } else if (field3f8[0x7] != 0) {
        _ZN8Vector3iaSERKS_(vec3, (int*)(field3f8 + 0x10));
        angle = *(short*)(field3f8 + 0x1c);
    } else {
        _ZN8Vector3iaSERKS_(vec3, (int*)&GetThreeWordsAt0x70((Owner_1e80c*)((char*)dataBase + 0x6c)));
        angle = GetSignedFieldAt0x7c((S_e820*)((char*)dataBase + 0x6c));
    }

    int value = func_02030f30(angle);

    for (i = 0; i < field2a04[0xf7c]; i++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x800(battleStruct, (field2a04 + i)[0xf78]);
        if (c != 0) {
            func_020399b0(c, *(unsigned short*)dataBase, vec3, value);
        }
    }

    if (field2a04[0xf7d] != 0) {
        struct CombatantStruct* c = GetCombatantWithFlag0x800(battleStruct, 0xce);
        if (c != 0) {
            func_020399b0(c, *(unsigned short*)dataBase, vec3, value);
        }
    }
}
