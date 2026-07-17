#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void RefreshRefIfFlagged_02217e70(char *self);
bool IsContextInactive(ProcessorContext* context);

extern void* data_ov031_0224e69c;

// USA: func_ov031_0221a854
ARM void MaybeRefreshRef_0221a854(void) {
    void* ptr = data_ov031_0224e69c;
    if (ptr == 0 || *(int*)((char*)ptr + 0x1000 + 0xbac) == 0) {
        return;
    }
    if (IsContextInactive((ProcessorContext*)((char*)ptr + 0x1b40))) {
        return;
    }
    ptr = data_ov031_0224e69c;
    RefreshRefIfFlagged_02217e70((char*)ptr + 8);
}
