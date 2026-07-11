#include <globaldefs.h>

// USA: func_02037ad8
ARM void SetShortAt0xa0(unsigned char* obj, short value) {
    *(short*)(obj + 0xa0) = value;
}
