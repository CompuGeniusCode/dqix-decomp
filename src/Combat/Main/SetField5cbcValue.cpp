#include <globaldefs.h>

// USA: func_02010810
ARM void SetField5cbcValue(char* obj, int value) {
    *(int*)(obj + 0x5cbc) = value;
}
