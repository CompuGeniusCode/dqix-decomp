#include <globaldefs.h>

struct Obj020b4020 {
    unsigned char* code;
    char pad4[4];
    unsigned int flags;
};

typedef void (*OpcodeHandler020b4020)(struct Obj020b4020*, unsigned int);

extern OpcodeHandler020b4020 data_020f1e08[];

// USA: func_020b4020
ARM void RunOpcodeLoop020b4020(struct Obj020b4020* obj) {
    unsigned char op;
    do {
        obj->flags &= ~0x40;
        op = obj->code[0];
        data_020f1e08[op & 0x1f](obj, op & 0xe0);
    } while (!(obj->flags & 0x20));
}
