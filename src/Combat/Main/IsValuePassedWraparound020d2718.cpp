#include <globaldefs.h>

unsigned int DisableInterrupts();
unsigned int RestoreInterrupts(unsigned int mask);

struct GlobalListState020d2718 {
    unsigned int field0;
    unsigned int field4;
};
extern struct GlobalListState020d2718 data_02112780;

#pragma optimize_for_size off

// USA: func_020d2718
ARM int IsValuePassedWraparound020d2718(unsigned int x) {
    unsigned int mask = DisableInterrupts();
    unsigned int cur = data_02112780.field4;
    int result;
    if (x > cur) {
        if ((x - cur) < 0x80000000u) {
            result = 0;
        } else {
            result = 1;
        }
    } else {
        result = (cur - x) < 0x80000000u;
    }
    RestoreInterrupts(mask);
    return result;
}
