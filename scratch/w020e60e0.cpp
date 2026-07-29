#include <globaldefs.h>
#pragma define_section initcode ".init" RX

struct Struct020f0d70 {
    unsigned char pad[0x14];
    int field_0x14;
    int field_0x18;
};

extern struct Struct020f0d70 data_020f0d70;

// USA: func_020e60e0
extern "C" __declspec(initcode) ARM void func_020e60e0(void) {
    data_020f0d70.field_0x18 = data_020f0d70.field_0x14 + 0xb;
}
