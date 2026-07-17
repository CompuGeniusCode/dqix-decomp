#include <globaldefs.h>

int IncrementCounters_0218f2f0(void*);

// USA: func_ov016_0218e72c
ARM int CallIfNonNullBool_0218e72c(void* obj) {
    if (obj == NULL) return 0;
    return IncrementCounters_0218f2f0(obj) == 1;
}
