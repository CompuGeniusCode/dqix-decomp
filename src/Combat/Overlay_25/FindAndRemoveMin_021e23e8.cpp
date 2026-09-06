#include <globaldefs.h>

struct Node021e23e8 {
    char pad0[1];
    unsigned char val;
    char pad2[6];
    struct Node021e23e8* next;
};
struct List021e23e8 {
    struct Node021e23e8* head;
};

// USA: func_ov025_021e23e8
ARM struct Node021e23e8* FindAndRemoveMin_021e23e8(struct List021e23e8* list) {
    struct Node021e23e8* cur = list->head;
    struct Node021e23e8* prev = NULL;
    unsigned int bestVal = 0xff;
    struct Node021e23e8* best = NULL;
    struct Node021e23e8* bestPrev = NULL;
    while (cur != NULL) {
        unsigned char v = cur->val;
        if (v < bestVal) {
            bestPrev = prev;
            best = cur;
            bestVal = v;
        }
        prev = cur;
        cur = cur->next;
    }
    if (best != NULL) {
        if (bestPrev != NULL) {
            bestPrev->next = best->next;
        } else {
            list->head = best->next;
        }
    }
    return best;
}
