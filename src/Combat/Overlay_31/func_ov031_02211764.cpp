#include <globaldefs.h>

extern "C" int func_ov031_022119d0(int* out, int* mapped);

struct Struct0224e598_02211764 { int field0; int field4; };
extern Struct0224e598_02211764 data_ov031_0224e598;

// USA: func_ov031_02211764
extern "C" ARM int func_ov031_02211764(int* out, int* mapped) {
    int cat = func_ov031_022119d0(out, mapped);
    if (cat != 0) return cat;
    if (out != 0) {
        *out = data_ov031_0224e598.field4;
    }
    if (mapped != 0) {
        switch (data_ov031_0224e598.field0) {
        case 0:
            *mapped = 0;
            break;
        case 2: case 3: case 4: case 5: case 6:
        case 16: case 17:
            *mapped = 6;
            break;
        case 1: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
        default:
            *mapped = 7;
            break;
        }
    }
    return data_ov031_0224e598.field0;
}
