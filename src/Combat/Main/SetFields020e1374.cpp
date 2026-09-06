#include <globaldefs.h>

struct Setter020e1374 {
    char pad[0xc];
    unsigned int a;
    unsigned int b;
    unsigned char c;
};

// USA: func_020e1374
ARM void SetFields020e1374(struct Setter020e1374* p, unsigned int a, unsigned int b, int c) {
    p->a = a;
    p->b = b;
    p->c = (unsigned char)c;
}
