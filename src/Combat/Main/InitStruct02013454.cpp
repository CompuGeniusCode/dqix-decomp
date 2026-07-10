#include <globaldefs.h>

struct TrackerState;
void ResetTrackerState(struct TrackerState* state);

// USA: func_02013454
ARM void InitStruct02013454(char* obj) {
    *(int*)(obj + 0x0) = -1;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
    *(int*)(obj + 0x54) = 0;
    ResetTrackerState((struct TrackerState*)(obj + 0x4));
    *(int*)(obj + 0x48) = 0;
    *(int*)(obj + 0x4c) = 0;
    *(int*)(obj + 0x50) = 0;
}
