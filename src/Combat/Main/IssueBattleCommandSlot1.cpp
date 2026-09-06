#include <globaldefs.h>

extern "C" int func_020d40bc(int, int);
int GetBattleReadyCode(void);
void SetBattleContextArrayEntry(int index, int value);

// USA: func_020d5004
ARM int IssueBattleCommandSlot1(int arg) {
    int r = GetBattleReadyCode();
    if (r != 0) return r;
    SetBattleContextArrayEntry(1, arg);
    r = func_020d40bc(1, 0);
    if (r == 0) r = 2;
    return r;
}
