#include <globaldefs.h>
#include "System/ProcessorContext.h"
#include "System/Interrupts.h"

struct Node { char unk[0x10]; struct Node* next; struct Node* prev; };
struct List { char unk[0x88]; struct Node* head; struct Node* tail; };
void AppendToList(struct List* list, struct Node* node);

struct LockNode020c8074 {
    unsigned char unk[8];
    void* owner;
    int refCount;
};

// USA: func_020c8074  (semantic: AcquireNodeRef020c8074)
#pragma optimize_for_size off
extern "C" ARM void func_020c8074(struct LockNode020c8074* obj) {
    int state = DisableIRQInterrupts();
    ProcessorContext* current = data_02111304.activeContext;
retry:
    {
        void* owner = obj->owner;
        if (owner != 0) goto check_owner;
        obj->owner = current;
        obj->refCount += 1;
        AppendToList((struct List*)current, (struct Node*)obj);
        goto done;
    check_owner:
        if (owner != current) goto blocked;
        obj->refCount += 1;
        goto done;
    blocked:
        current->unknown_84 = (unsigned int)obj;
        BlockCurrentContext((BlockedContextList*)obj);
        current->unknown_84 = 0;
        goto retry;
    }
done:
    SetIRQInterruptState(state);
}
