#include <globaldefs.h>

extern "C" int func_ov000_02170c7c(int);

struct Elem0217f5e4 { char pad[0x25]; signed char field25; char pad2[0x28 - 0x26]; };
struct Struct0217f5e4 { char pad[0x170]; struct Elem0217f5e4* arr170; };

// USA: func_ov000_0217f5e4
ARM void SetFieldRange0217f5e4(struct Struct0217f5e4* obj, int key) {
    if (key == 0) return;
    signed char v = (signed char)func_ov000_02170c7c(key);
    for (int i = 7; i < 0x11; i++) {
        obj->arr170[i].field25 = v;
    }
}
