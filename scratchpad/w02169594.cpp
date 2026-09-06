#include <globaldefs.h>

struct Struct_0205ba68;
void SetupPointerTable0205ba68(struct Struct_0205ba68* s, int a, int b, int mode);

struct Node0205bacc;
void SetField0AndPropagate0205bacc(struct Node0205bacc* s, int val);

struct Struct_0205bcdc;
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* s, int index);

struct NodeWithFlag0205bacc {
    char pad[0x3c];
    unsigned char flag3c;
};

extern "C" void func_0205bb04(struct NodeWithFlag0205bacc* s, int n);

// USA: func_ov003_02169594
#pragma optimize_for_size off
ARM void SetupDualNodeState_02169594(unsigned char* self) {
    int a, b, c, d, e;
    switch (self[0x194]) {
    case 1:
        a = 1;
        b = 3;
        c = b;
        d = a;
        e = *(signed char*)(self + 0x4ed);
        break;
    case 2:
        e = *(signed char*)(self + 0x4ee);
        a = 4;
        b = 1;
        c = a;
        d = b;
        break;
    }
    struct NodeWithFlag0205bacc* p138 = (struct NodeWithFlag0205bacc*)(self + 0x138);
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(self + 0xe8), a, b, 0);
    SetupPointerTable0205ba68((struct Struct_0205ba68*)p138, a, b, 0);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(self + 0xe8), c);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)p138, c);
    *(int*)(self + 0xec) = d;
    *(int*)((char*)p138 + 4) = d;
    SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)(self + 0xe8), e);
    func_0205bb04(p138, e);
    p138->flag3c = 0;
}
