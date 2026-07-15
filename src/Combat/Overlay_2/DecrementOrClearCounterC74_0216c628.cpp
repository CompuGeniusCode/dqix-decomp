#include <globaldefs.h>

// USA: func_ov002_0216c628
ARM int DecrementOrClearCounterC74_0216c628(unsigned char* obj, int amount) {
    int v = *(int*)(obj + 0x1000 + 0xc74);
    if (v > amount) {
        *(int*)(obj + 0x1000 + 0xc74) = v - amount;
        goto ret1;
    }
    *(int*)(obj + 0x1000 + 0xc74) = 0;
    return 0;
ret1:
    return 1;
}
