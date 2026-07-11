#include <globaldefs.h>

extern "C" int func_020d424c(int, int);
extern "C" int func_020d40bc(int, int);
void SetBattleContextArrayEntry(int index, int value);

// USA: func_020d4efc
ARM int IssueBattleCommandSlot5(int arg) {
    int r = func_020d424c(1, 1);
    if (r != 0) return r;
    SetBattleContextArrayEntry(5, arg);
    r = func_020d40bc(5, 0);
    if (r == 0) r = 2;
    return r;
}
