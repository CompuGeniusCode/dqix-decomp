#include <globaldefs.h>

// USA: func_02037ac8
ARM void SetIntAt0xa4(unsigned char* obj, int value) {
    *(int*)(obj + 0xa4) = value;
}
