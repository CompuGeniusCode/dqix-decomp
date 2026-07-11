#include <globaldefs.h>

extern "C" int func_020d40bc(int, int, int, int, int, int);
int GetBattleReadyCode(void);
void SetBattleContextArrayEntry(int index, int value);

#pragma optimize_for_size off
// USA: func_020d6ad4
ARM int IssueBattleCommandSlot29(int arg, int a, int b, int c, unsigned short d) {
    int r = GetBattleReadyCode();
    if (r != 0) return r;
    SetBattleContextArrayEntry(0x1d, arg);
    r = func_020d40bc(0x1d, 4, a, b, c, d);
    if (r == 0) r = 2;
    return r;
}
