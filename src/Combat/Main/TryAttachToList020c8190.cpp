#include <globaldefs.h>

struct Node { char unk[0x10]; struct Node* next; struct Node* prev; };
struct List { char unk[0x88]; struct Node* head; struct Node* tail; };
void AppendToList(struct List* list, struct Node* node);

struct Entry020c8190 {
    char pad0[0x8];
    struct List* cachedList;
    int refCount;
};

unsigned int DisableInterrupts();
unsigned int RestoreInterrupts(unsigned int mask);

extern struct List* data_02111304[2];

// USA: func_020c8190
#pragma optimize_for_size off
ARM int TryAttachToList020c8190(struct Entry020c8190* self) {
    unsigned int state = DisableInterrupts();
    struct List* list = data_02111304[1];
    int ret;
    if (self->cachedList == NULL) {
        self->cachedList = list;
        self->refCount += 1;
        AppendToList(list, (struct Node*)self);
        ret = 1;
    } else if (self->cachedList != list) {
        ret = 0;
    } else {
        self->refCount += 1;
        ret = 1;
    }
    RestoreInterrupts(state);
    return ret;
}
