#include <globaldefs.h>
void ClearAndFreeAllNodes020c78e8(struct List020c7234*);

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);

struct LinkAnchor;
struct LinkNode;
void UnlinkNode(struct LinkAnchor* anchor, struct LinkNode* node);


extern int data_02111304;

struct RefNode020c80f8 {
    unsigned char unk[8];
    void* owner;
    int refCount;
};

// USA: func_020c80f8
ARM void ReleaseNodeRef020c80f8(struct RefNode020c80f8* node) {
    unsigned int mask = DisableInterrupts();
    void* currentOwner = *(void**)((char*)&data_02111304 + 4);
    if (node->owner == currentOwner) {
        if (--node->refCount == 0) {
            UnlinkNode((struct LinkAnchor*)currentOwner, (struct LinkNode*)node);
            node->owner = 0;
            ClearAndFreeAllNodes020c78e8((struct List020c7234*)(node));
        }
    }
    RestoreInterrupts(mask);
}
