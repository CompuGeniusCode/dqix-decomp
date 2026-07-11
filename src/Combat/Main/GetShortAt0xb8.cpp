#include <globaldefs.h>

struct ShortField0xb8_0209cae8 {
    char pad[0xb8];
    short value;
};

// USA: func_0209cae8
ARM short GetShortAt0xb8(struct ShortField0xb8_0209cae8* obj) {
    return obj->value;
}
