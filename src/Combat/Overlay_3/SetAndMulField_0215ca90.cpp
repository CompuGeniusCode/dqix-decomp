#include <globaldefs.h>

// USA: func_ov003_0215ca90
ARM void SetAndMulField_0215ca90(void* obj, int v) {
    *(int*)((char*)obj + 0x3c8) = v;
    *(int*)((char*)obj + 0x3cc) = v * (*((unsigned char*)obj + 0x3c3));
}
