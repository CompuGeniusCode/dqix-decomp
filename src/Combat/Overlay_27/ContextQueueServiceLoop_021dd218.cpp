#include <globaldefs.h>
#include "System/ProcessorContext.h"
#include "System/Interrupts.h"

struct WaitNode021dd218 {
    WaitNode021dd218* next;
    unsigned int isActive : 1;
    unsigned int priority : 31;
    void (*onDequeue)(WaitNode021dd218*);
    void (*onComplete)(WaitNode021dd218*);
};

struct QueueContext021dd218 {
    ProcessorContext ctx;
    WaitNode021dd218* volatile queueHead;
    WaitNode021dd218 sentinel;
};

// USA: func_ov027_021dd218  (semantic: ContextQueueServiceLoop_021dd218)
#pragma optimize_for_size off
extern "C" ARM void func_ov027_021dd218(QueueContext021dd218* obj) {
    for (;;) {
        WaitNode021dd218* node;
        int state = DisableIRQInterrupts();
        if (obj->queueHead == NULL) {
            int priority = 0;
            WaitNode021dd218* none = NULL;
            do {
                ChangeContextPriority((ProcessorContext*)obj, priority);
                BlockCurrentContext((BlockedContextList*)none);
            } while (obj->queueHead == NULL);
        }
        node = obj->queueHead;
        obj->queueHead = obj->queueHead->next;
        ChangeContextPriority((ProcessorContext*)obj, node->priority);
        SetIRQInterruptState(state);

        if (node->onDequeue != NULL) node->onDequeue(node);

        state = DisableIRQInterrupts();
        void (*onComplete)(WaitNode021dd218*) = node->onComplete;
        unsigned int currentPriority = GetContextPriority((ProcessorContext*)obj);
        unsigned int newPriority;
        if (obj->queueHead == NULL) {
            newPriority = 0;
        } else if (currentPriority < obj->queueHead->priority) {
            newPriority = obj->queueHead->priority;
        } else {
            newPriority = currentPriority;
        }
        if (newPriority != currentPriority) {
            ChangeContextPriority((ProcessorContext*)obj, newPriority);
        }

        node->next = NULL;
        node->isActive = 0;
        if (onComplete != NULL) onComplete(node);

        if (node == &obj->sentinel) break;
        SetIRQInterruptState(state);
    }
    ContextExecutionReturnProc();
}
