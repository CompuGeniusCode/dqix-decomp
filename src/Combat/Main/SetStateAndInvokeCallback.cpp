#include <globaldefs.h>
int IssueBattleCommandSlot2(int);

extern char data_021015a0;
void SetStateFromField0x2(unsigned short*);

// USA: func_0202df10
ARM int SetStateAndInvokeCallback() {
    *(int*)(&data_021015a0 + 0x10) = 3;
    if (IssueBattleCommandSlot2((int)((void*)SetStateFromField0x2)) != 2) {
        *(int*)(&data_021015a0 + 0x10) = 9;
        return 0;
    }
    *(short*)(&data_021015a0 + 0xe) = 0;
    return 1;
}
