#include <globaldefs.h>

// USA: func_020da2e4
ARM void ResetFields020da2e4(unsigned char* obj) {
    *(int*)(obj + 8) = -1;
    *(int*)(obj + 0) = -1;
    *(unsigned char*)(obj + 4) = 0;
}
