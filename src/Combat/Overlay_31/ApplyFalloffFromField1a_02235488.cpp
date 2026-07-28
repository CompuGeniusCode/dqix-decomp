#include <globaldefs.h>

int Divide32(int numer, unsigned int denom);
extern "C" void func_ov031_0223689c(int val);
extern "C" void func_ov031_022368bc(int arg2, int arg3);

struct StateStruct02235488 { unsigned char pad[0x1a]; unsigned char field1a; };
extern StateStruct02235488* data_ov031_02290cf4;

// USA: func_ov031_02235488  (semantic: ApplyFalloffFromField1a_02235488)
extern "C" ARM void func_ov031_02235488(int arg0) {
    int diff = data_ov031_02290cf4->field1a - arg0;
    int adiff = diff < 0 ? -diff : diff;
    int level;
    if (adiff < 2) {
        level = 0;
    } else if (adiff >= 6) {
        level = 0x7f;
    } else {
        level = Divide32(0x7f, 6 - adiff);
    }
    func_ov031_0223689c(level);

    int v;
    if (adiff < 2) {
        v = -256;
    } else if (adiff >= 6) {
        v = 256;
    } else {
        v = Divide32(0x200, 6 - adiff) - 0x100;
    }
    func_ov031_022368bc(0xffff, v);
}
