#include <globaldefs.h>

struct Ctx020359c8;
int CheckAndToggleFlag0x200000(struct Ctx020359c8* obj);
extern "C" void func_0203574c(void* obj);

struct Obj0207e924;
void DispatchByFlag42_020356f0(unsigned char*);
void InvokeHandlerAndClearFlags020b3814(void);
int InvokeField54IfFlag0xa8Bit0Set(struct Obj0207e924*, int, int, int, int);

struct Battler02035db8 {
    char pad0[8];
    struct Obj0207e924* field_8;
    char pad2[0x60];
    unsigned int field_6c;
};

// USA: func_02035db8
ARM int RunActionWithHandlerReset02035db8(struct Battler02035db8* a, int b, int c, int d, int e) {
    if (CheckAndToggleFlag0x200000((struct Ctx020359c8*)a) == 0) return 0;
    if (a->field_6c & 0x800) b = 0;
    DispatchByFlag42_020356f0((unsigned char*)a);
    func_0203574c(a);
    InvokeHandlerAndClearFlags020b3814();
    return InvokeField54IfFlag0xa8Bit0Set(a->field_8, b, c, d, e);
}
