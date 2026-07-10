#include <globaldefs.h>

struct Struct020349c8 {
    unsigned short field0;
    unsigned short field2;
};

// USA: func_020349c8
ARM float GetNormalizedField2_020349c8(struct Struct020349c8* p) {
    return (float)(unsigned int)(p->field2 * 31) / 65535.0f;
}
