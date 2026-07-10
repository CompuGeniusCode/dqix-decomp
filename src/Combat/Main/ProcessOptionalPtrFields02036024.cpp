#include <globaldefs.h>

struct Obj02036024 {
    unsigned char pad[0x50];
    void* field50;
    void* field54;
    void* field58;
};

extern "C" void func_02031278(void* p);
extern "C" void func_02031234(void* p);
extern "C" void func_020311f0(void* p);

// USA: func_02036024
ARM void ProcessOptionalPtrFields02036024(struct Obj02036024* obj) {
    if (obj->field58 != NULL) func_02031278(obj->field58);
    if (obj->field54 != NULL) func_02031234(obj->field54);
    if (obj->field50 != NULL) func_020311f0(obj->field50);
}
