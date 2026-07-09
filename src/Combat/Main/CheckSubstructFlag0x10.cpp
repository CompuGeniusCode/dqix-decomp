#include <globaldefs.h>

// USA: func_0204936c
ARM int CheckSubstructFlag0x10(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p == 0) return 0;
    return (p[8] & 0x10) != 0;
}
