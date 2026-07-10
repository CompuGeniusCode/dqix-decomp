#include <globaldefs.h>

extern unsigned short data_02111634;

// USA: func_020c8c50
ARM void SetActiveTimerBit(int bit) {
    data_02111634 |= (1 << bit);
}
