#include <globaldefs.h>

int ClearBattleSubEffectAt0x800(void* p);
void SetField0x48UnlessState9Or10(int arg);
int IssueBattleCommandSlot1(int arg);
void SetState9DispatchOrInvokeCallback(unsigned short* obj);

extern char data_021015a0;
extern char data_02102be0;

// USA: func_0202dd28
ARM void TryIssueBattleCommandAndUpdateState(void) {
    if (*(int*)(&data_021015a0 + 0x10) == 5) {
        int r = ClearBattleSubEffectAt0x800(&data_02102be0);
        if (r) {
            SetField0x48UnlessState9Or10(r);
        }
    }

    *(int*)(&data_021015a0 + 0x10) = 3;
    int result = IssueBattleCommandSlot1((int)SetState9DispatchOrInvokeCallback);
    if (result == 2) {
        result = 1;
    } else {
        SetField0x48UnlessState9Or10(result);
        result = 0;
    }

    if (result == 0) {
        *(int*)(&data_021015a0 + 0x10) = 10;
    }
}
