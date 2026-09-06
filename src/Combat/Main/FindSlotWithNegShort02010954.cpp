#include <globaldefs.h>

// USA: func_02010954
ARM void* FindSlotWithNegShort02010954(char* base) {
    int i;
    for (i = 0; i < 4; i++) {
        if (*(short*)(base + i * 0x964 + 0x9dc) < 0) {
            return base + 0x474 + i * 0x964;
        }
    }
    return NULL;
}
