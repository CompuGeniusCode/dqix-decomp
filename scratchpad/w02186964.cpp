#include <globaldefs.h>

struct Struct_0205bef8;
ARM void Init0205bef8(struct Struct_0205bef8* s);

struct Struct_0205ba68;
ARM void SetupPointerTable0205ba68(struct Struct_0205ba68* s, int a, int b, int mode);

struct Node0205bacc;
ARM void SetField0AndPropagate0205bacc(struct Node0205bacc* s, int val);

extern "C" void func_0205bb04(void* s, int n);

struct Actor02186964 {
    char pad0[0x744];
    unsigned char idBytes[8];
    unsigned char f74c;
    char pad1[0xb10 - 0x74d];
    signed char f0xb10;
    char pad2[0xb18 - 0xb11];
    int f0xb18;
    char pad3[0xb28 - 0xb1c];
    unsigned char f0xb28;
    unsigned char f0xb29;
};

// USA: func_02186964
ARM void UpdateFieldSet02186964(struct Actor02186964* actor) {
    int one = 1;
    int count = 1;
    int fourvar = 1;
    int best = 0;

    if (actor->f0xb10 == 3) {
        fourvar = count = actor->f74c;
        int idx = 0;
        for (idx = 0; idx < count; idx++) {
            if (actor->f0xb28 == actor->idBytes[idx]) {
                best = idx;
                break;
            }
        }
        if (count > 6) {
            actor->f0xb18 |= 0x10;
            int lim = actor->f0xb29 + 5;
            if (best > lim) {
                actor->f0xb29 = best - 5;
            } else if (best < actor->f0xb29) {
                actor->f0xb29 = best;
            }
        }
    }

    struct Struct_0205ba68* p = (struct Struct_0205ba68*)((char*)actor + 0x750);
    Init0205bef8((struct Struct_0205bef8*)p);
    SetupPointerTable0205ba68(p, one, count, 0);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)p, fourvar);
    ((int*)p)[1] = one;
    func_0205bb04(p, best);
}
