#include <globaldefs.h>

// USA: func_020709ac
ARM int GetIntAt0xc(unsigned char* obj) {
    return *(int*)(obj + 0xc);
}
