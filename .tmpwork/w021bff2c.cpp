#include <globaldefs.h>

struct BattleStruct;
struct BattleStruct* GetBattleStruct(void);
struct CombatantStruct;
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void SetByteField0x253(void* obj);
struct ShortField02033e2c;
void ClearField0xc602033e2c(struct ShortField02033e2c* obj);
struct Foo02033b58;
void SetByteSavingPrevious(struct Foo02033b58* p, unsigned char v);
extern "C" int func_ov017_0218b5b0(void);
int GetFieldIfFlag4(char* obj);
void SetField0x23cTrue(void* obj);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);

// USA: func_ov017_021bff2c
ARM void ClearCombatantStateAndFlags_021bff2c(void) {
    struct BattleStruct* battle = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battle);
    SetByteField0x253(combatant);
    ClearField0xc602033e2c((struct ShortField02033e2c*)combatant);
    SetByteSavingPrevious((struct Foo02033b58*)combatant, 0);
    int h = func_ov017_0218b5b0();
    int flag = GetFieldIfFlag4((char*)battle);
    if (flag != 0) {
        SetField0x23cTrue((void*)(long)flag);
    }
    if (h != 0) {
        ClearBitsInField4((unsigned int*)h, 0x80);
    }
}
