#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Node02169b2c { char pad[4]; struct Node02169b2c* next; };
void AppendNodeRecursive02169b2c(struct Node02169b2c* node, struct Node02169b2c* newNode);

struct QueueDescriptor02169b78 { char pad[8]; struct Node02169b2c* head; };
struct Struct02184264_02169b78 { char pad0[4]; struct QueueDescriptor02169b78* qd; };
extern struct Struct02184264_02169b78 data_ov000_02184264;

// USA: func_ov000_02169b78  (semantic: EnqueueEventNode_02169b78)
extern "C" ARM void func_ov000_02169b78(struct Node02169b2c* newNode) {
    struct QueueDescriptor02169b78* qd = data_ov000_02184264.qd;
    if (!qd) {
        return;
    }
    struct Node02169b2c* head = qd->head;
    if (!head) {
        qd->head = newNode;
        newNode->next = NULL;
        return;
    }
    AppendNodeRecursive02169b2c(head, newNode);
}
