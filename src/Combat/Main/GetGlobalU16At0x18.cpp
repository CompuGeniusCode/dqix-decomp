#include <globaldefs.h>

struct GlobalBlock2111224_18 {
    unsigned char _pad[0x18];
    unsigned short field;
};
extern struct GlobalBlock2111224_18 data_02111224;

// USA: func_020c4bc8
ARM unsigned short GetGlobalU16At0x18(void) {
    return data_02111224.field;
}
