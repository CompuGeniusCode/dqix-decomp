#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);
int CheckState0x11(void);

struct State02111818_020cf08c {
    unsigned char pad0[0xc];
    unsigned int busy;   // 0xc
    unsigned int f10;     // 0x10
    unsigned int f14;      // 0x14
    unsigned char gap1[4]; // 0x18
    unsigned int f1c;        // 0x1c
    unsigned int f20;         // 0x20
    unsigned int f24;          // 0x24
};

extern struct State02111818_020cf08c data_02111818;

// USA: func_020cf08c
ARM int EnterCombatMode020cf08c(int a, int b, int c) {
    unsigned int mask = DisableInterrupts();
    if (data_02111818.busy != 0) {
        RestoreInterrupts(mask);
        return 1;
    }
    data_02111818.busy = 1;
    RestoreInterrupts(mask);
    data_02111818.f20 = 0;
    data_02111818.f24 = 0;
    data_02111818.f14 = a;
    data_02111818.f10 = b;
    data_02111818.f1c = c;
    return CheckState0x11() ? 0 : 3;
}
