#include <globaldefs.h>

struct BitfieldStruct02227558 {
    unsigned int low4 : 4;
    unsigned int rest : 28;
};

extern int data_ov031_02250c0c;

// USA: func_ov031_02227558
ARM unsigned int GetField8Low4_02227558(void) {
    struct BitfieldStruct02227558* s = (struct BitfieldStruct02227558*)((char*)&data_ov031_02250c0c + 0x8);
    return s->low4;
}
