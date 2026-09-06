#include <globaldefs.h>

struct ShortField0xb4_0205eac8 {
    char pad[0xb4];
    short field;
};

// USA: func_0205eac8
ARM int GetShortAt0xb4(struct ShortField0xb4_0205eac8* obj) {
    return obj->field;
}
