#include <globaldefs.h>

extern volatile unsigned char data_02109da4[];
extern signed char data_02109dae[];

// USA: func_020a1eb0
ARM int PeekInputLogA(void) {
    if (data_02109da4[0] != 0) {
        return data_02109dae[data_02109da4[0] - 1];
    }
    return -1;
}
