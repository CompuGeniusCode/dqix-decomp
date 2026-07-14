#include <globaldefs.h>
struct BlockedContextList;
void UnblockContexts(struct BlockedContextList*);

struct Node020c72bc {
    char pad0[8];
    int f8;
    int fc;
    Node020c72bc* next;
    Node020c72bc* prev;
};

struct List020c72bc {
    Node020c72bc* head;
    Node020c72bc* tail;
};

extern "C" void* UnknownImplementedFunction_020c72bc(void* input);

// USA: func_020c8154
ARM void DrainNodeList020c8154(void* owner) {
    if (*(Node020c72bc**)((char*)owner + 0x88) == NULL) {
        return;
    }
    do {
        Node020c72bc* node = (Node020c72bc*)UnknownImplementedFunction_020c72bc((char*)owner + 0x88);
        node->fc = 0;
        node->f8 = 0;
        UnblockContexts((struct BlockedContextList*)(node));
    } while (*(Node020c72bc**)((char*)owner + 0x88) != NULL);
}
