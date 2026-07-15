#include <globaldefs.h>

struct BitfieldByte022140cc {
    unsigned char lowBits : 2;
    unsigned char nextBits : 2;
    unsigned char rest : 4;
};
struct EntityStruct022140cc { unsigned char pad[0xd0b]; struct BitfieldByte022140cc field3339; };

// USA: func_ov031_022140cc
ARM unsigned int GetField3339Bits23_022140cc(struct EntityStruct022140cc* e) {
    return e->field3339.nextBits == 1 ? 0xc0000 : 0x80000;
}
