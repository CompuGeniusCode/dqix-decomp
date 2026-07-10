#include <globaldefs.h>

// USA: func_02085930
ARM float GetPackedRateModifierField0(char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 1.0f;
    return (float)((*(int*)(obj + 0x300) << 26) >> 26) / 10.0f;
}
