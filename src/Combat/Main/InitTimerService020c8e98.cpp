#include <globaldefs.h>

void SetActiveTimerBit(int bit);
unsigned int DisableInterruptBits(unsigned int mask);

struct Data02111648 {
    unsigned short flag;   /* 0x0 */
    char pad0[2];
    int field4;            /* 0x4 */
    int field8;            /* 0x8 */
};
extern struct Data02111648 data_02111648;

// USA: func_020c8e98
ARM void InitTimerService020c8e98(void) {
    if (data_02111648.flag != 0) {
        return;
    }
    data_02111648.flag = 1;
    SetActiveTimerBit(1);
    data_02111648.field4 = 0;
    data_02111648.field8 = 0;
    DisableInterruptBits(0x10);
}
