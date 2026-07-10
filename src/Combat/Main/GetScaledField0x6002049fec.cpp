#include <globaldefs.h>

extern "C" float func_020349c8(void* p);

// USA: func_02049fec
ARM float GetScaledField0x6002049fec(char* obj) {
    char* x = *(char**)(obj + 0x13c);
    if (x == NULL) return 0.0f;
    return func_020349c8(x + 0x60);
}
