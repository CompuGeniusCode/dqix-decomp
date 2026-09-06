#include <globaldefs.h>

struct StructF0x64_0203cdf8 {
    char pad[0x64];
    int field64;
};

// USA: func_0203cdf8
ARM int GetField0x64(struct StructF0x64_0203cdf8* obj) {
    return obj->field64;
}
