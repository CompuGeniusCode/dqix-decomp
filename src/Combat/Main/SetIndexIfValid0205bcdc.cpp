#include <globaldefs.h>

extern "C" void func_0205bb04(void*, int);

struct Struct_0205bcdc {
    int field0;
    char pad[0x2c];
    int field30;
};

// USA: func_0205bcdc
ARM void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* s, int index) {
    if (index < 0) return;
    if (s->field0 <= index) return;
    s->field30 = -1;
    func_0205bb04(s, index);
}
