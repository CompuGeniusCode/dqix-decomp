#include <globaldefs.h>

// USA: func_020c7ca8
ARM void SetFieldAt0xb4(unsigned char* obj, int value) {
    *(int*)(obj + 0xb4) = value;
}
