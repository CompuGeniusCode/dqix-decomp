#include <globaldefs.h>

struct Struct02226f68_p { unsigned char pad[0x116]; unsigned char field116; };
struct Struct02226f68_base { unsigned char field0; unsigned char pad1[3]; Struct02226f68_p* field4; };
extern Struct02226f68_base data_ov031_02250c04;

extern "C" int func_ov031_0221c4bc(void*);

// USA: func_ov031_02226f68
#pragma optimize_for_size off
ARM int CheckField116OrSetFlag_02226f68(void) {
    if (!func_ov031_0221c4bc(data_ov031_02250c04.field4)) {
        data_ov031_02250c04.field0 = 1;
        return 1;
    }
    unsigned char v = data_ov031_02250c04.field4->field116;
    if (v == 1) goto ret0;
    if ((unsigned char)(v + 0xfd) > 2) goto ret2;
ret0:
    return 0;
ret2:
    return 2;
}
