#include <globaldefs.h>
#include "System/ProcessorContext.h"

void CancelAndRearmAlarm_0220dab4(void);
extern int data_ov031_0224e540;
extern int data_ov031_0224e544;

// USA: func_ov031_0220f28c
ARM void SetFieldAndMaybeCall_0220f28c(unsigned short *arg) {
    if (arg[0] != 0x12) {
        return;
    }
    *(int*)((char*)&data_ov031_0224e540 + 0x24) = arg[1];
    if (arg[1] != 0) {
        CancelAndRearmAlarm_0220dab4();
    }
    UnblockContexts((struct BlockedContextList*)&data_ov031_0224e544);
}
