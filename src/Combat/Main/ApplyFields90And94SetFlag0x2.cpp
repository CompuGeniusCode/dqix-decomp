#include <globaldefs.h>

// USA: func_0207eb9c
ARM void ApplyFields90And94SetFlag0x2(unsigned char* obj) {
    int a = *(int*)(obj + 0x90);
    if (a != 0) {
        *(int*)(obj + 0x34) = a;
    }
    {
        int b = *(int*)(obj + 0x94);
        if (b != 0) {
            *(int*)(obj + 0x38) = b;
        }
    }
    *(int*)(obj + 0xa8) |= 2;
}
