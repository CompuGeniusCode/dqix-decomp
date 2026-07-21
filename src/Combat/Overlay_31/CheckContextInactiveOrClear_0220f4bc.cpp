#include <globaldefs.h>
#include "System/ProcessorContext.h"

bool IsContextInactive(ProcessorContext* context);
extern void* data_ov031_0224e580;

extern "C" void func_ov031_0220f518(int);
void MarkGlobal0224e580ContextReadyGuarded_0220f558(void);

// USA: func_ov031_0220f4bc  (semantic: CheckContextInactiveOrClear_0220f4bc)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_0220f4bc(void) {
    if (data_ov031_0224e580 == NULL) return 1;
    func_ov031_0220f518(0);
    if (!IsContextInactive((ProcessorContext*)((char*)data_ov031_0224e580 + 0x34))) {
        MarkGlobal0224e580ContextReadyGuarded_0220f558();
        return 0;
    }
    data_ov031_0224e580 = NULL;
    return 1;
}
