#include <globaldefs.h>

extern int data_020ef078;
extern "C" void func_02003ce8(void* dst, void* fmt, void* src);

struct Obj0204887c {
    char pad0[0x148];
    char* field148;
};

// USA: func_0204887c
ARM void ReplaceEntryAndFormat0204887c(struct Obj0204887c* obj, char* newVal) {
    char* old = obj->field148;
    obj->field148 = newVal;
    if (old == NULL) return;
    func_02003ce8(obj->field148 + 0x2c, &data_020ef078, old + 0x2c);
}
