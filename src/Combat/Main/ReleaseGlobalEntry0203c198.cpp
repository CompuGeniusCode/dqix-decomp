#include <globaldefs.h>

extern char* data_02105244;
void ReleaseEntry0203c54c(char* obj, short* idxPtr);

// USA: func_0203c198
ARM void ReleaseGlobalEntry0203c198(char* obj) {
    if (data_02105244 == NULL) return;
    ReleaseEntry0203c54c(data_02105244, (short*)(obj + 0x14));
    *(short*)(obj + 0x14) = -1;
}
