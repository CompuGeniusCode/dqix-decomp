#include <globaldefs.h>

extern "C" int func_020d424c(int, int);
extern "C" int func_020d40bc(int, int, int);
void SetBattleContextArrayEntry(int index, int value);
void* GetBattleContext(void);

// USA: func_020d51a8
ARM int IssueBattleCommandSlot8(int a0, int a1) {
    int r = func_020d424c(1, 2);
    if (r != 0) {
        return r;
    }
    char* ctx = (char*)GetBattleContext();
    *(unsigned short*)(ctx + 0x150) = 0;
    *(int*)(ctx + 0x14c) = 0;
    SetBattleContextArrayEntry(8, a0);
    r = func_020d40bc(8, 1, a1);
    if (r == 0) {
        r = 2;
    }
    return r;
}
