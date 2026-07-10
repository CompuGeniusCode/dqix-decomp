#include <globaldefs.h>

extern "C" void func_020bcc7c(void*);

struct Foo020bcbc4 { char pad[0x24]; signed int bit0 : 1; };

// USA: func_020bcbc4
ARM void CallIfFlag0x24Bit0(struct Foo020bcbc4* obj) {
    if (obj->bit0) {
        func_020bcc7c(obj);
    }
}
