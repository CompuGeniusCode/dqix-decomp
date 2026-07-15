#include <globaldefs.h>

struct Holder021e5ff0 {
    char pad0[0xc];
    unsigned char* inner;
};

extern struct Holder021e5ff0 data_ov025_021ef988;

struct Param021e5ff0 { char pad[8]; unsigned short field_8; };

// USA: func_ov025_021e5ff0
ARM int SetField021e5ff0(struct Param021e5ff0* p) {
    *(unsigned short*)(data_ov025_021ef988.inner + 0x21c) = p->field_8;
    return 1;
}
