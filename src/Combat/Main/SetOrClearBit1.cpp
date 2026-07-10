#include <globaldefs.h>

void SetOrClearBit(unsigned char* obj, int bit, int set);

// USA: func_0201bf70
ARM void SetOrClearBit1(unsigned char* obj, int set) {
    SetOrClearBit(obj, 1, set);
}
