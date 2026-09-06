#include <globaldefs.h>
int IssueBattleCommandSlot11(int);

extern "C" int func_0202d108(void);
void SetField0x48UnlessState9Or10(int arg);

// USA: func_0202d0e0
ARM int IsDispatchComplete0202d0e0(void) {
    int r = IssueBattleCommandSlot11((int)(func_0202d108));
    if (r == 2) {
        return 1;
    }
    SetField0x48UnlessState9Or10(r);
    return 0;
}
