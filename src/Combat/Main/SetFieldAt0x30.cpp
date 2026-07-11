#include <globaldefs.h>

// USA: func_0205bc24
ARM void SetFieldAt0x30(void* obj, int value) {
    *(int*)((char*)obj + 0x30) = value;
}
