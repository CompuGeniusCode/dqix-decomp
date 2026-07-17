#include <globaldefs.h>

struct DispatchStruct_0220e1e0 {
    unsigned short f0;
    unsigned short f2;
};

extern "C" void func_ov031_0220da1c(int);
void RequestBattleSlot1IfIdle_0220db6c(void);
void ReadClearAndDispatch_0220d984(int, int, int, int);

// USA: func_ov031_0220e1e0
ARM void DispatchByType_0220e1e0(struct DispatchStruct_0220e1e0 *s) {
    switch (s->f2) {
        case 0:
            func_ov031_0220da1c(3);
            ReadClearAndDispatch_0220d984(0, 0, 0, 0x783);
            break;
        case 1:
            RequestBattleSlot1IfIdle_0220db6c();
            break;
        case 2:
        case 3:
        case 4:
            func_ov031_0220da1c(0xb);
            ReadClearAndDispatch_0220d984(7, 0, 0, 0x793);
            break;
    }
}
