#include <globaldefs.h>

int GetBattleReadyCode(void);
void CleanDataCacheRange(int addr, int size);
void SetBattleContextArrayEntry(int index, int value);
extern "C" int func_020d40bc(int a, int b, unsigned int c, int d);

// USA: func_020d68dc
ARM int SubmitBattleAction020d68dc(int value, unsigned int count, void* data) {
    int state = GetBattleReadyCode();
    if (state != 0) return state;
    if (count > 3) return 6;
    if (count != 0) {
        if (data == 0) return 6;
        CleanDataCacheRange((int)data, 0x50);
    }
    SetBattleContextArrayEntry(0x14, value);
    int r = func_020d40bc(0x14, 2, count, (int)data);
    return (r == 0) ? 2 : r;
}
