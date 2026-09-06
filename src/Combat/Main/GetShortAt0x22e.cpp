#include <globaldefs.h>

struct ShortField0x22e_020968c4 {
    char pad[0x22e];
    short field;
};

// USA: func_020968c4
ARM int GetShortAt0x22e(struct ShortField0x22e_020968c4* obj) {
    return obj->field;
}
