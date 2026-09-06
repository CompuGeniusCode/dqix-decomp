#include <globaldefs.h>

struct CombatState020e3c34;
extern void Init020e3c34(CombatState020e3c34* p);

struct Struct020e3ec0 {
    unsigned char byte0;
    unsigned char byte1;
};

// USA: func_020e3ec0
ARM void InitWithFlag020e3ec0(Struct020e3ec0* p) {
    Init020e3c34((CombatState020e3c34*)p);
    p->byte1 = 1;
}
