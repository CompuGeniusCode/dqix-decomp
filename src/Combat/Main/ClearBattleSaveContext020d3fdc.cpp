#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);
int GetBattleStateCode(void);
extern "C" int func_020d424c(int a, int b);
void ClearBit0At027FFF96(void);
void SetIndexedFlagBit020cae24(int index, int value);

struct BattleState021142e0_020d3fdc {
    unsigned short state;   // 0x0
    unsigned char pad[2];
    unsigned int f4;         // 0x4
};

extern struct BattleState021142e0_020d3fdc data_021142e0;

// USA: func_020d3fdc
ARM int ClearBattleSaveContext020d3fdc(void) {
    unsigned int mask = DisableInterrupts();
    if (GetBattleStateCode() != 0) {
        RestoreInterrupts(mask);
        return 3;
    }
    int r = func_020d424c(1, 0);
    if (r != 0) {
        return r;
    }
    ClearBit0At027FFF96();
    SetIndexedFlagBit020cae24(0xa, 0);
    data_021142e0.f4 = 0;
    data_021142e0.state = 0;
    RestoreInterrupts(mask);
    return 0;
}
