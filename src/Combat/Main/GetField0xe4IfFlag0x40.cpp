#include <globaldefs.h>

struct BitFlag02033f44 {
    char pad[0xe0];
    unsigned char bits0_5 : 6;
    unsigned char flag40 : 1;
    unsigned char bit7 : 1;
    char pad2[3];
    int field_e4;
};

// USA: func_02033f44
ARM int* GetField0xe4IfFlag0x40(struct BitFlag02033f44* p) {
    return p->flag40 ? &p->field_e4 : 0;
}
