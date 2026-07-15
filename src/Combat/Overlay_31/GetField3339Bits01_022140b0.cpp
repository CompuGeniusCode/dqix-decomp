#include <globaldefs.h>

struct BitfieldByte022140b0 {
    unsigned char lowBits : 2;
    unsigned char nextBits : 2;
    unsigned char rest : 4;
};
struct EntityStruct022140b0 { unsigned char pad[0xd0b]; struct BitfieldByte022140b0 field3339; };

// USA: func_ov031_022140b0
ARM unsigned int GetField3339Bits01_022140b0(struct EntityStruct022140b0* e) {
    return e->field3339.lowBits == 1 ? 0x30000 : 0x20000;
}
