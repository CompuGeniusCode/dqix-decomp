#include <globaldefs.h>

struct Node020c7234 {
    char pad[0x78];
    void* f78;
    struct Node020c7234* prev;
    struct Node020c7234* next;
};

struct List020c7234 {
    struct Node020c7234* head;
    struct Node020c7234* tail;
};

unsigned int DisableInterrupts();
unsigned int RestoreInterrupts(unsigned int mask);
struct Node020c7234* UnlinkHeadNode020c7234(struct List020c7234* list);
extern "C" void func_020c7394(void);

// USA: func_020c78e8
ARM void ClearAndFreeAllNodes020c78e8(struct List020c7234* list) {
    unsigned int state = DisableInterrupts();
    if (list->head != NULL) {
        if (list->head != NULL) {
            do {
                struct Node020c7234* node = UnlinkHeadNode020c7234(list);
                *(unsigned int*)((char*)node + 0x64) = 1;
                node->f78 = NULL;
                node->next = NULL;
                node->prev = NULL;
            } while (list->head != NULL);
        }
        list->tail = NULL;
        list->head = NULL;
        func_020c7394();
    }
    RestoreInterrupts(state);
}
