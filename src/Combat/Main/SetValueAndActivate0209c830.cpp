#include <globaldefs.h>

struct Struct0209c830 {
    char pad[0xc9];
    unsigned char active;
    char pad2[4];
    unsigned short value;
};

// USA: func_0209c830
ARM void SetValueAndActivate0209c830(struct Struct0209c830* p, unsigned short value) {
    p->value = value;
    p->active = 1;
}
