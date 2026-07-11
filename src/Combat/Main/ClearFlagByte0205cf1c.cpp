#include <globaldefs.h>

struct Struct0205cf1c {
    char pad[0x95];
    unsigned char field95;
};

// USA: func_0205cf1c
ARM void ClearFlagByte0205cf1c(struct Struct0205cf1c* s) {
    s->field95 = 0;
}
