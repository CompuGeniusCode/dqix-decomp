#include <globaldefs.h>

extern "C" void func_020cfcf8(int, int);

// USA: func_020d0040
ARM void SelectBattleContextMode2(int x) {
    func_020cfcf8(x, 2);
}
