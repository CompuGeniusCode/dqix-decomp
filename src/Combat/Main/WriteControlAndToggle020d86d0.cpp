#include <globaldefs.h>

struct IntState020d86d0 {
    unsigned char field_0;
    unsigned char pad1[3];
    unsigned int field_4;
};
extern IntState020d86d0 data_0214e4a0;

// USA: func_020d86d0
ARM void WriteControlAndToggle020d86d0(int a, int b) {
    *(unsigned int*)0x04000540 = a | (b << 1);
    data_0214e4a0.field_0 = (data_0214e4a0.field_0 == 0) ? 1 : 0;
}
