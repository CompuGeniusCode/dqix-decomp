#include <globaldefs.h>

extern "C" int func_ov016_0218f16c(void*);

// USA: func_ov016_0218e708
ARM int CallIfNonNullBool_0218e708(void* obj) {
    if (obj == NULL) return 0;
    return func_ov016_0218f16c(obj) == 1;
}
