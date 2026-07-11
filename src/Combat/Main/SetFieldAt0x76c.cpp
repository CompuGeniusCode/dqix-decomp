#include <globaldefs.h>

// USA: func_020263dc
ARM void SetFieldAt0x76c(unsigned char* obj, void* value) {
    *(void**)(obj + 0x76c) = value;
}
