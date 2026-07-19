#include <globaldefs.h>

struct SetFields4And8Struct_021d4cc0 {
    unsigned int unk0;
    unsigned int field4;
    unsigned int field8;
};

// USA: func_ov017_021d4cc0  (semantic: SetFields4And8_021d4cc0)
extern "C" ARM void func_ov017_021d4cc0(SetFields4And8Struct_021d4cc0* obj, unsigned int a, unsigned int b) {
    obj->field8 = a;
    obj->field4 = b;
}
