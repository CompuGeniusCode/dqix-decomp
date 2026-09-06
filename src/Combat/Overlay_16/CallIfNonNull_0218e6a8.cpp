#include <globaldefs.h>

struct Obj0218ef2c;
int GetFlagValue_0218ef2c(struct Obj0218ef2c* o);

// USA: func_ov016_0218e6a8
ARM int CallIfNonNull_0218e6a8(void* p) {
    if (p == NULL) {
        return 0;
    }
    return GetFlagValue_0218ef2c((struct Obj0218ef2c*)p);
}
