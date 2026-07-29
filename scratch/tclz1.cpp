#include <globaldefs.h>

// USA: func_TEST
ARM unsigned int TestClz(unsigned int v) {
    return __CLZ(v);
}
