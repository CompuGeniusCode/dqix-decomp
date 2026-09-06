#include <globaldefs.h>

// USA: func_020b035c
ARM void SetIndexedFieldAt0x8020b035c(char* base, int index, int value) {
    *(int*)(base + (index << 2) + 0x8) = value;
}
