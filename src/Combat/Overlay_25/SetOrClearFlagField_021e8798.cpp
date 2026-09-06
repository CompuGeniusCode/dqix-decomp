#include <globaldefs.h>

struct Holder021e8798 {
    char pad0[0xc];
    unsigned char* inner;
};

extern struct Holder021e8798 data_ov025_021ef988;

struct Param021e8798 { char pad[8]; short field_8; };

// USA: func_ov025_021e8798
ARM int SetOrClearFlagField_021e8798(struct Param021e8798* p) {
    short val = p->field_8;
    if (val > 0) {
        *(short*)(data_ov025_021ef988.inner + 0x220) = val;
    } else if (val == -2) {
        *(short*)(data_ov025_021ef988.inner + 0x220) = 0x1e;
    } else {
        *(short*)(data_ov025_021ef988.inner + 0x220) = -1;
    }
    return 1;
}
