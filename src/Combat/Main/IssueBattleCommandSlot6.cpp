#include <globaldefs.h>

extern "C" int func_020d424c(int, int);
extern "C" int func_020d40bc(int, int);
void SetBattleContextArrayEntry(int index, int value);

// USA: func_020d4f3c
ARM int IssueBattleCommandSlot6(int arg) {
    int r = func_020d424c(1, 2);
    if (r != 0) return r;
    SetBattleContextArrayEntry(6, arg);
    r = func_020d40bc(6, 0);
    if (r == 0) r = 2;
    return r;
}
