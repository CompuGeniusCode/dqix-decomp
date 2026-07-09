#include <globaldefs.h>

// USA: func_02040648
ARM void ClearFlag0x1(unsigned int* obj) {
    *obj &= ~1;
}
