#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj021bb088 {
    int field0;
    int field4;
    unsigned char field8[0x1c];
    int field24;
    unsigned int field28;
};

// USA: func_ov017_021bb088
ARM void InitTimerObj_021bb088(Obj021bb088* p) {
    p->field0 = 0;
    p->field4 = 0;
    memset(&p->field8, 0, 0x1c);
    p->field24 = -1;
    p->field28 &= 0xf8000000;
    p->field28 &= ~0xf8000000;
}
