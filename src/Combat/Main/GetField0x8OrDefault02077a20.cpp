#include <globaldefs.h>

struct Inner02077a20 {
    char pad[8];
    short val;
};

struct Outer02077a20 {
    char pad[0x184];
    struct Inner02077a20* inner;
};

// USA: func_02077a20
ARM int GetField0x8OrDefault02077a20(struct Outer02077a20* p) {
    struct Inner02077a20* inner = p->inner;
    return inner != NULL ? inner->val : 0x1000;
}
