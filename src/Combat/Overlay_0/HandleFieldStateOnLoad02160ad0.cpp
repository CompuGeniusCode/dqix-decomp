#include <globaldefs.h>

void ApplyFieldGroups021742c8(void* obj);
void HandleFieldFlagsAndState021870c0(void* obj);
struct Obj021d8c94;
void CallIfFieldNot0Or3_021d8c94(struct Obj021d8c94* obj);
void CallDispatchIfFlagSet_021eb4f4(char* obj);
extern "C" void func_ov013_02184aec(void* obj);

// USA: func_ov000_02160ad0  (semantic: HandleFieldStateOnLoad02160ad0)
extern "C" ARM void func_ov000_02160ad0(char* obj) {
    if (*(int*)(obj + 0x5000 + 0x5f8) == 0) return;
    if (*(void**)(obj + 0x5000 + 0x5cc) != 0) {
        CallDispatchIfFlagSet_021eb4f4(*(char**)(obj + 0x5000 + 0x5cc));
    }
    if (*(void**)(obj + 0x5000 + 0x574) != 0) {
        func_ov013_02184aec(*(void**)(obj + 0x5000 + 0x574));
        if (*(void**)(obj + 0x5000 + 0x578) == 0) return;
        HandleFieldFlagsAndState021870c0(*(void**)(obj + 0x5000 + 0x578));
        return;
    }
    if (*(struct Obj021d8c94**)(obj + 0x5000 + 0x588) != 0) {
        CallIfFieldNot0Or3_021d8c94(*(struct Obj021d8c94**)(obj + 0x5000 + 0x588));
        return;
    }
    if (*(int*)(obj + 0x5000 + 0x5f4) & 0x40000) return;
    ApplyFieldGroups021742c8(obj + 0x760 + 0x3000);
}
