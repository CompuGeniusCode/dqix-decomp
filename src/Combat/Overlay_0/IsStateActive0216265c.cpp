#include <globaldefs.h>

// USA: func_ov000_0216265c
ARM int IsStateActive0216265c(void* objRaw) {
    int v = *(int*)((char*)objRaw + 0xea8);
    switch (v) {
        case 4:
        case 6:
        case 9:
        case 0xa:
        case 0xb:
            return 1;
        default:
            return 0;
    }
}
