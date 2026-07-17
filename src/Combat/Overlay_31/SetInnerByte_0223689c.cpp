#include <globaldefs.h>

extern char* data_ov031_02290d00;
struct Outer020bc158;
ARM void SetInnerByte_0223689c(struct Outer020bc158 *p, unsigned char val);

// USA: func_ov031_0223689c
ARM void SetInnerByte41AtOffset94_0223689c(unsigned char val) {
    SetInnerByte_0223689c((struct Outer020bc158*)(data_ov031_02290d00 + 0x94), val);
}
