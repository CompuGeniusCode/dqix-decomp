#include <globaldefs.h>

struct ShortField0x28_02099fe8 {
    char pad[0x28];
    short field;
};

// USA: func_02099fe8
ARM int GetShortAt0x28(struct ShortField0x28_02099fe8* obj) {
    return obj->field;
}
