#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
extern "C" void func_ov017_021d6134(void*, int);

struct Sub0x150_02162d68 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_ov001_02162d68
ARM int SetFlagIfCombatantBitlear_02162d68_02162d68(void* ctx) {
    struct CombatantStruct* c = GetCombatantWithFlag0x800(GetBattleStruct(), 0);
    if (c == NULL) {
        return 0;
    }
    struct Sub0x150_02162d68* sub = (struct Sub0x150_02162d68*)GetFieldAt0x150((unsigned char*)c);
    func_ov017_021d6134(ctx, sub->bit0 == 0);
    return 1;
}
