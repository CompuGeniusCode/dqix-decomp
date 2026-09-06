#include <globaldefs.h>

void RunTurnStartHooks02155108(void* obj);

struct Obj021e3184 {
    void* field0;
    char pad[0x4e2];
    signed char field4e6;
};

// USA: func_ov023_021e3184  (semantic: CallIfFlagValidAndFieldSet_021e3184)
extern "C" ARM void func_ov023_021e3184(struct Obj021e3184* obj) {
    signed char c = obj->field4e6;
    if (c == 0) return;
    if (c == -1) return;
    void* v = obj->field0;
    if (v == NULL) return;
    RunTurnStartHooks02155108(v);
}
