#include <globaldefs.h>

extern "C" unsigned int* func_020d6c00(void);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);

// USA: func_020dc2bc
ARM void OrGlobalFlag0x40(void) {
    OrBitsIntoField0(func_020d6c00(), 0x40);
}
