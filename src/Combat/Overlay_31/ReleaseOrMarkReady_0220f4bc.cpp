#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern void* data_ov031_0224e580;
int ClearFieldsThenForward_0220f518(void* arg);
bool IsContextInactive(ProcessorContext* context);
void MarkGlobal0224e580ContextReadyGuarded_0220f558(void);

#pragma optimize_for_size off

// USA: func_ov031_0220f4bc
ARM int ReleaseOrMarkReady_0220f4bc(void) {
    if (data_ov031_0224e580 == NULL) {
        return 1;
    }
    ClearFieldsThenForward_0220f518(0);
    if (!IsContextInactive((ProcessorContext*)((char*)data_ov031_0224e580 + 0x34))) {
        MarkGlobal0224e580ContextReadyGuarded_0220f558();
        return 0;
    }
    data_ov031_0224e580 = NULL;
    return 1;
}
