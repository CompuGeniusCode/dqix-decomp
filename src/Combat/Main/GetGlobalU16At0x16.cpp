#include <globaldefs.h>

struct GlobalBlock2111224_16 {
    unsigned char _pad[0x16];
    unsigned short field;
};
extern struct GlobalBlock2111224_16 data_02111224;

// USA: func_020c4bb8
ARM unsigned short GetGlobalU16At0x16(void) {
    return data_02111224.field;
}
