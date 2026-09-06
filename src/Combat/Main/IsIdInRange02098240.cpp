#include <globaldefs.h>

// USA: func_02098240
ARM int IsIdInRange02098240(int a, int id) {
    int base = 0xc545;
    if (id >= base && id <= base + 0x16) return 1;
    return 0;
}
