#include <globaldefs.h>

struct Struct02237e9c { unsigned char pad[0x1b]; signed char field1b; };
extern Struct02237e9c* data_ov031_02290d10;

// USA: func_ov031_02237e9c
ARM signed char GetField1b_02237e9c(void) {
    return data_ov031_02290d10->field1b;
}
