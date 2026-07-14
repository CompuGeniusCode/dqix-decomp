#include <globaldefs.h>

void LockCardReadManager(unsigned short, int);
typedef void (*LockCardReadManagerRawFn)(int, int);

// USA: func_020d0040
ARM void SelectBattleContextMode2(int x) {
    ((LockCardReadManagerRawFn)&LockCardReadManager)(x, 2);
}
