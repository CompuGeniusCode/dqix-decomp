#include <globaldefs.h>
void ReleaseGlobalEntry0203c198(char* obj);

// USA: func_ov000_02174dc0
ARM void ReleaseEntriesTwoGroups02174dc0(void* obj) {
    int i;
    for (i = 0; i < 3; i++) {
        ReleaseGlobalEntry0203c198((char*)obj + 0x1b0c + i * 0x18);
    }
    for (i = 0; i < 8; i++) {
        ReleaseGlobalEntry0203c198((char*)obj + 0x1c5c + i * 0x18);
    }
}
