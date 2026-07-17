#include <globaldefs.h>

// USA: func_ov025_021ed350
ARM void SetShortArrayEntry128_021ed350(char* obj, int idx, unsigned short val) {
    *(unsigned short*)(obj + idx * 2 + 0x80) = val;
}
