#include <globaldefs.h>

extern char data_021015a0;
void SetField0x48UnlessState9Or10(int arg);
extern "C" void func_0202dd98(void);
int IssueBattleCommandSlot13(int a0, unsigned int a1);
void DispatchField0x2OrSetState1_0202d5ec(unsigned short* obj);
void TryIssueBattleCommandAndUpdateState(void);

// USA: func_0202d584
extern "C" ARM void func_0202d584(unsigned short* obj) {
    unsigned short v = obj[1];
    if (v != 0) {
        SetField0x48UnlessState9Or10(v);
        func_0202dd98();
        return;
    }

    int result;
    *(int*)(&data_021015a0 + 0x10) = 3;
    result = IssueBattleCommandSlot13((int)DispatchField0x2OrSetState1_0202d5ec, 0);
    if (result == 2) {
        result = 1;
    } else {
        SetField0x48UnlessState9Or10(result);
        TryIssueBattleCommandAndUpdateState();
        result = 0;
    }
    if (result == 0) {
        *(int*)(&data_021015a0 + 0x10) = 9;
    }
}
