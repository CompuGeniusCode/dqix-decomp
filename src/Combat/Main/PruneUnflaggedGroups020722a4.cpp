#include <globaldefs.h>

struct Node020722a4 {
    char pad0[0x10];
    unsigned int flags;
    int pad1[2];
    struct Node020722a4* next;
};

// USA: func_020722a4
ARM void PruneUnflaggedGroups020722a4(struct Node020722a4** list, int n) {
    int i;
    int matchCount;
    int kept;
    struct Node020722a4* segHead;
    struct Node020722a4* tail;
    struct Node020722a4* firstTail;
    struct Node020722a4* cur;
    struct Node020722a4* last;

    if (n <= 0) return;

    segHead = *list;
    i = 0;
    matchCount = 0;
    kept = 0;
    tail = 0;
    firstTail = 0;
    cur = segHead;

    while (cur != 0) {
        if ((cur->flags << 9) >> 31) matchCount++;
        i++;
        last = cur;
        cur = cur->next;
        if (i == n || cur == 0) {
            if (matchCount > 0) {
                kept++;
                if (tail != 0) tail->next = segHead;
                else *list = segHead;
                tail = last;
            }
            i = 0;
            matchCount = 0;
            segHead = cur;
            if (firstTail == 0) firstTail = last;
        }
    }

    if (kept == 0) {
        if (firstTail != 0) firstTail->next = 0;
    } else {
        if (tail != 0) tail->next = 0;
    }
}
