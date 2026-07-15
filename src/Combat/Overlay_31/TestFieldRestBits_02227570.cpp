#include <globaldefs.h>

struct BitfieldStruct02227570 {
    unsigned int low4 : 4;
    unsigned int rest : 28;
};
extern int data_ov031_02250c0c;

// USA: func_ov031_02227570
ARM int TestFieldRestBits_02227570(unsigned int mask) {
    struct BitfieldStruct02227570* s = (struct BitfieldStruct02227570*)((char*)&data_ov031_02250c0c + 0x8);
    return (mask & s->rest) != 0;
}
