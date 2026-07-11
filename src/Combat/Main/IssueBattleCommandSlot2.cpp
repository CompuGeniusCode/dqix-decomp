#include <globaldefs.h>

extern "C" int func_020d424c(int, int);
extern "C" int func_020d40bc(int, int);
void SetBattleContextArrayEntry(int index, int value);

// USA: func_020d503c
ARM int IssueBattleCommandSlot2(int arg) {
    int r = func_020d424c(1, 2);
    if (r != 0) return r;
    SetBattleContextArrayEntry(2, arg);
    r = func_020d40bc(2, 0);
    if (r == 0) r = 2;
    return r;
}
