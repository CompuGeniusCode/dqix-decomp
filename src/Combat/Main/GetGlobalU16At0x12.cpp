#include <globaldefs.h>

struct GlobalBlock2111224_12 {
    unsigned char _pad[0x12];
    unsigned short field;
};
extern struct GlobalBlock2111224_12 data_02111224;

// USA: func_020c4b98
ARM unsigned short GetGlobalU16At0x12(void) {
    return data_02111224.field;
}
