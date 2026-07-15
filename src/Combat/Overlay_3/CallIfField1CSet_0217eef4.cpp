#include <globaldefs.h>

struct Obj0217eef4 { char pad[0x1c]; void* field1c; };

extern "C" void func_ov009_02184ca4(void*);

// USA: func_ov003_0217eef4
ARM void CallIfField1CSet_0217eef4(struct Obj0217eef4* obj) {
    if (obj->field1c) {
        func_ov009_02184ca4(obj->field1c);
    }
}
