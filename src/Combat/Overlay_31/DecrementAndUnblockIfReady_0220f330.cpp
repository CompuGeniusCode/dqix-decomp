#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void func_01ff8000(void);

struct GuardedBlockList_0220f330 {
    BlockedContextList list;
    void* field8;
    int counter;
};

// USA: func_ov031_0220f330  (semantic: DecrementAndUnblockIfReady_0220f330)
extern "C" ARM void func_ov031_0220f330(struct GuardedBlockList_0220f330* obj) {
    if (obj->field8 != (void*)func_01ff8000) {
        return;
    }
    if (--obj->counter != 0) {
        return;
    }
    obj->field8 = NULL;
    UnblockContexts(&obj->list);
}
