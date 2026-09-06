#include <globaldefs.h>

struct BattleStruct;

struct BattleStruct* GetBattleStruct();
void* GetField0x3f8Address(struct BattleStruct* battleStruct);
void InitStruct02070378(char* obj);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// USA: func_ov017_0219c6f4  (semantic: InitAndCopyVecsFromCombatant_0219c6f4)
extern "C" ARM void* func_ov017_0219c6f4(char* combatant) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    char* obj = (char*)GetField0x3f8Address(battleStruct);
    InitStruct02070378(obj);

    *(short*)(obj + 0x0) = *(int*)(combatant + 0x1c);
    _ZN8Vector3iaSERKS_((int*)(obj + 0x10), (int*)(combatant + 0x20));

    *(short*)(obj + 0x1c) = *(short*)(combatant + 0x50);
    *(unsigned char*)(obj + 0xb) = *(int*)(combatant + 0x6c);
    _ZN8Vector3iaSERKS_((int*)(obj + 0x30), (int*)(combatant + 0x20));

    _ZN8Vector3iaSERKS_((int*)(obj + 0x3c), (int*)(combatant + 0x2c));
    _ZN8Vector3iaSERKS_((int*)(obj + 0x48), (int*)(combatant + 0x38));
    _ZN8Vector3iaSERKS_((int*)(obj + 0x54), (int*)(combatant + 0x44));

    *(unsigned char*)(obj + 0xc) = 1;
    *(unsigned char*)(obj + 0x7) = 1;

    return obj;
}
