#include <globaldefs.h>

// USA: func_02053cc4
ARM void SetFieldAt0x188(unsigned char* obj, int value) {
    *(int*)(obj + 0x188) = value;
}
