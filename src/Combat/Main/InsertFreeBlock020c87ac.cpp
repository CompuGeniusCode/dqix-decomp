#include <globaldefs.h>

struct FreeBlock020c87ac {
    struct FreeBlock020c87ac* prev;
    struct FreeBlock020c87ac* next;
    unsigned int size;
};

// USA: func_020c87ac
ARM struct FreeBlock020c87ac* InsertFreeBlock020c87ac(struct FreeBlock020c87ac* head, struct FreeBlock020c87ac* blk) {
    struct FreeBlock020c87ac* prev = NULL;
    struct FreeBlock020c87ac* cur = head;
    if (cur != NULL) {
        for (;;) {
            if (blk <= cur) break;
            prev = cur;
            cur = cur->next;
            if (cur == NULL) break;
        }
    }
    blk->prev = prev;
    blk->next = cur;
    if (cur != NULL) {
        cur->prev = blk;
        if ((struct FreeBlock020c87ac*)((char*)blk + blk->size) == cur) {
            blk->size += cur->size;
            cur = cur->next;
            blk->next = cur;
            if (cur != NULL) {
                cur->prev = blk;
            }
        }
    }
    if (prev != NULL) {
        prev->next = blk;
        if ((struct FreeBlock020c87ac*)((char*)prev + prev->size) == blk) {
            prev->size += blk->size;
            prev->next = cur;
            if (cur != NULL) {
                cur->prev = prev;
            }
        }
        return head;
    }
    return blk;
}
