#include <globaldefs.h>

// USA: func_020e1354
ARM void ClearHeaderFields020e1354(unsigned char* p) {
    *(int*)(p + 0) = 0;
    *(int*)(p + 4) = 0;
    p[8] = 0;
}
