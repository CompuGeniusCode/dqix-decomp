#include <globaldefs.h>
#include "std_library_functions.h"

struct State0204166c;
extern void Forward020416c0(struct State0204166c* s);

// USA: func_02043040
ARM void InitCombatSlots02043040(char* obj) {
    int i;

    memset(obj + 0x2cc, 0, 4);
    *(int*)(obj + 0x9b4) = 0;

    for (i = 0; i < 0x80; i++) {
        Forward020416c0((struct State0204166c*)(obj + 0x9b8 + i * 0x1c));
        *(unsigned char*)(obj + i + 0x17b8) = 0;
    }

    *(int*)(obj + 0x1868) = 0;
    *(int*)(obj + 0x9a0) = 0;
    *(unsigned char*)(obj + 0x19b2) = 0;
    *(unsigned char*)(obj + 0x19b4) = 0;
}
