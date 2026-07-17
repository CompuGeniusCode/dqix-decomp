#include <globaldefs.h>

struct BattleStruct;
struct CombatantStruct;

struct BattleStruct* GetBattleStruct();
void* GetField0x3f8Address(struct BattleStruct* battleStruct);
extern "C" unsigned short* func_02012fe4(void* fieldPtr);
struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
void InitStruct02070378(char* obj);
void CopyVec3(int* dst, int* src);

// USA: func_ov017_0219bcac
ARM void InitFieldsFromCombatant_0219bcac(unsigned char flag) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    char* obj = (char*)GetField0x3f8Address(battleStruct);
    unsigned short* val = func_02012fe4(obj);
    char* combatant = (char*)GetCombatantAtField0x3ac(battleStruct);
    InitStruct02070378(obj);
    *(short*)(obj + 0x0) = *val;
    CopyVec3((int*)(obj + 0x10), (int*)(combatant + 0x44));
    *(short*)(obj + 0x1c) = *(int*)(combatant + 0x54);
    *(unsigned char*)(obj + 0x7) = 1;
    *(unsigned char*)(obj + 0x2) = 1;
    *(unsigned char*)(obj + 0x9) = 0;
    *(unsigned char*)(obj + 0xa) = 1;
    *(unsigned char*)(obj + 0x65) = flag;
}
