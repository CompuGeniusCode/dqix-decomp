#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

void FormatEffectStats02072c9c(int combatantId, char* buf);
extern "C" int func_ov017_0218b5b0(void);

struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);

extern char data_020f0cff[];

// USA: func_02072d58
ARM void FormatAndAppendCombatMessage02072d58(int combatantId, char* statsBuf, char* outBuf) {
    FormatEffectStats02072c9c(combatantId, statsBuf);

    int base = func_ov017_0218b5b0();
    struct HeadNode02046b24** headTable = *(struct HeadNode02046b24***)((char*)base + 0x36fc);
    int flag = 0;

    if (GetHeadNodeIdOrMinusOne(headTable) == 0xa) {
        struct CombatantStruct* c = GetCombatantFromList(GetBattleStruct(), combatantId);
        if (c != NULL) {
            flag = *(unsigned char*)(*(int*)((char*)c + 0x138) + 0x26);
        }
    }

    if (flag != 0) {
        sprintf(outBuf, data_020f0cff, statsBuf, 0x62);
        sprintf(statsBuf, data_020f0cff, statsBuf, 0x66);
    } else {
        sprintf(statsBuf, data_020f0cff, statsBuf, 0x6e);
        sprintf(outBuf, data_020f0cff, statsBuf, 0x65);
    }

    struct CombatantStruct* c2 = GetCombatantWithFlag0x100(GetBattleStruct(), combatantId);
    if (c2 == NULL) {
        return;
    }

    int val = *(int*)((char*)c2 + 0x150);
    struct Flags02072d58 {
        unsigned char bit0 : 1;
        unsigned char rest : 7;
    };
    struct Flags02072d58* flagsField = (struct Flags02072d58*)(val + 0x49c);

    if (flagsField->bit0 == 1) {
        statsBuf[0] = 0x77;
    }
}
