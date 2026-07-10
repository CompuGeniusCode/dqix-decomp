#include <globaldefs.h>

extern "C" int func_020359c8(void*);

struct Obj0207e924;

void DispatchByFlag42_020356f0(unsigned char*);
int InvokeField54IfFlag0xa8Bit0Set(struct Obj0207e924*, int, int, int, int);

struct Battler02035e1c {
    char pad0[8];
    struct Obj0207e924* field_8;   // 0x8
    char pad2[0x60];
    unsigned int field_6c;         // 0x6c
};

// USA: func_02035e1c
ARM int RunActionIfReady02035e1c(struct Battler02035e1c* a, int b, int c, int d, int e) {
    if (func_020359c8(a) == 0) return 0;
    if (a->field_6c & 0x800) b = 0;
    DispatchByFlag42_020356f0((unsigned char*)a);
    return InvokeField54IfFlag0xa8Bit0Set(a->field_8, b, c, d, e);
}
