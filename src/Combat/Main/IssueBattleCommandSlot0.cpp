#include <globaldefs.h>

extern "C" int func_020d40bc(int, int, int, int, int, int);
int InitBattleModeF00(int a, int b);
void SetBattleContextArrayEntry(int index, int value);
void* GetBattleContext(void);

struct BattleCtx020d4fa4 {
    int field0;
    int field4;
    unsigned char pad8[8];
    int field10;
};

#pragma optimize_for_size off

// USA: func_020d4fa4
ARM int IssueBattleCommandSlot0(int a0, int a1, int a2, int a3) {
    int r = InitBattleModeF00(a0, a2);
    if (r != 0) {
        return r;
    }
    SetBattleContextArrayEntry(0, a1);
    struct BattleCtx020d4fa4* ctx = (struct BattleCtx020d4fa4*)GetBattleContext();
    r = func_020d40bc(0, 4, ctx->field0, ctx->field4, ctx->field10, a3);
    if (r == 0) {
        r = 2;
    }
    return r;
}
