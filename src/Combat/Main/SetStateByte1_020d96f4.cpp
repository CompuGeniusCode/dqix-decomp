#include <globaldefs.h>

struct GlobalState0214e4a8 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    int field4;
};

extern GlobalState0214e4a8 data_0214e4a8;

// USA: func_020d96f4
ARM unsigned char SetStateByte1_020d96f4(unsigned char v) {
    unsigned char old = data_0214e4a8.byte1;
    data_0214e4a8.byte1 = v;
    return old;
}
