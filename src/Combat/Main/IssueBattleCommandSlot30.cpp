#include <globaldefs.h>

void* GetBattleContext(void);
extern "C" int func_020d424c(int a, int b);
void SetBattleContextArrayEntry(int index, int value);
int CommitBattleContextBuffer020d4168(void* a, unsigned int b);

struct BattleReqBuf020d6b34 { short f0, f1, f2, f3, f4; };

#pragma optimize_for_size off

// USA: func_020d6b34
ARM int IssueBattleCommandSlot30(int a0, short a1, short a2, short a3, unsigned short a4) {
    struct BattleReqBuf020d6b34 buf;
    int r;
    GetBattleContext();
    r = func_020d424c(1, 2);
    if (r != 0) {
        return r;
    }
    SetBattleContextArrayEntry(0x1e, a0);
    buf.f0 = 0x1e;
    buf.f1 = a1;
    buf.f2 = a2;
    buf.f3 = a3;
    buf.f4 = a4;
    r = CommitBattleContextBuffer020d4168(&buf, 10);
    if (r == 0) {
        return 2;
    }
    return r;
}
