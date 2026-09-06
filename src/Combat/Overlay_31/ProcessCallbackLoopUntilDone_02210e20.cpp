#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern void* data_ov031_0224e588;

extern "C" void func_ov031_0221038c(int state);
void UnblockContexts(struct BlockedContextList* list);
void SetGlobal0224e588Deref_022103dc(void* value);
extern "C" int func_ov031_022104e4(void* buf);

#pragma optimize_for_size off
// USA: func_ov031_02210e20  (semantic: ProcessCallbackLoopUntilDone_02210e20)
extern "C" ARM void func_ov031_02210e20(void) {
    char buf[0x414];

    func_ov031_0221038c(0);
    UnblockContexts((struct BlockedContextList*)((char*)data_ov031_0224e588 + 0x204 + 0x800));

    int dead = *(volatile int*)((char*)data_ov031_0224e588 + 0x1b8);
    int state = *(volatile int*)data_ov031_0224e588;
    (void)dead;
    if (state != 7) return;

Loop:
    if (*(int*)((char*)data_ov031_0224e588 + 4) == 2) {
        SetGlobal0224e588Deref_022103dc((void*)5);
        return;
    }
    {
        unsigned int result = (unsigned int)func_ov031_022104e4(buf);
        void (*callback)(int, void*) = *(void(**)(int, void*))((char*)data_ov031_0224e588 + 0xa0c);
        if (callback != NULL) {
            callback(result, buf);
        }
        if (result < 4 || (int)result != *(int*)buf) {
            SetGlobal0224e588Deref_022103dc((void*)5);
            return;
        }
    }
    if (*(int*)data_ov031_0224e588 == 7) goto Loop;
}
