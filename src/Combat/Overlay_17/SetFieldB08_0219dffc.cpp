#include <globaldefs.h>

// USA: func_ov017_0219dffc
ARM void SetFieldB08_0219dffc(void* obj, int val) {
    *(int*)((char*)obj + 0x2000 + 0xb08) = val;
}
