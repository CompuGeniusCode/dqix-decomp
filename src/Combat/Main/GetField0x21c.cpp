#include <globaldefs.h>

struct S0204a438 {
    char pad[0x21c];
    void* field0x21c;
};

// USA: func_0204a438
ARM void* GetField0x21c(struct S0204a438* p) {
    return p->field0x21c;
}
