#include <globaldefs.h>

// USA: func_0203be58
ARM void SetByteAt0xc0203be58(char* base, int offset, int val) {
    *(base + offset + 0xc) = val;
}
