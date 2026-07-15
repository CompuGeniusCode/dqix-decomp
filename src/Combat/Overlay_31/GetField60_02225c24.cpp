#include <globaldefs.h>

struct EntityStruct02225c24 { unsigned char pad[0x60]; unsigned char field60; };
extern EntityStruct02225c24* data_ov031_02250c00;

// USA: func_ov031_02225c24
ARM unsigned char GetField60_02225c24(void) {
    return data_ov031_02250c00->field60;
}
