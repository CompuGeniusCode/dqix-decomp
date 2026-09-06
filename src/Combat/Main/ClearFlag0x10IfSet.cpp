#include <globaldefs.h>

struct Struct02074bd0 {
    char pad[0x10];
    unsigned char flag10;
};

extern "C" void func_02074c18(struct Struct02074bd0*);

// USA: func_02074bd0
ARM void ClearFlag0x10IfSet(struct Struct02074bd0* obj) {
    if (obj->flag10) {
        func_02074c18(obj);
        obj->flag10 = 0;
    }
}
