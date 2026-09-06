#include <globaldefs.h>

struct Struct0224c980_02200264 {
    char pad[0x24];
    unsigned int field0x24;
};

extern Struct0224c980_02200264 data_ov031_0224c980;

void CycleCurrentPriorityContexts();
void SleepCurrentContext(unsigned int);

// USA: func_ov031_02200264
ARM void DispatchContext02200264(void) {
    unsigned int v = data_ov031_0224c980.field0x24;
    if (v == 0) {
        CycleCurrentPriorityContexts();
    } else {
        SleepCurrentContext(v);
    }
}
