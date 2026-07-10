#include <globaldefs.h>

struct GlobalBlock2111224_14 {
    unsigned char _pad[0x14];
    unsigned short field;
};
extern struct GlobalBlock2111224_14 data_02111224;

// USA: func_020c4ba8
ARM unsigned short GetGlobalU16At0x14(void) {
    return data_02111224.field;
}
