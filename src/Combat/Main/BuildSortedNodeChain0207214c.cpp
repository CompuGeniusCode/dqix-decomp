#include <globaldefs.h>
struct SortNode0207214c* FindBestEntryAboveLimit(struct Container0207218c*, int);

struct SortNode0207214c {
    unsigned char pad0[0x18];
    short sortKey;
    unsigned char pad1a[2];
    struct SortNode0207214c* next;
};

struct SortList0207214c {
    struct SortNode0207214c* head;
};


// USA: func_0207214c
ARM void BuildSortedNodeChain0207214c(struct SortList0207214c* list) {
    struct SortNode0207214c* node;
    list->head = FindBestEntryAboveLimit((struct Container0207218c*)(list), (int)(-1));
    if (list->head == NULL) return;
    node = list->head;
    while (node != NULL) {
        struct SortNode0207214c* next = FindBestEntryAboveLimit((struct Container0207218c*)(list), (int)(node->sortKey));
        node->next = next;
        node = next;
    }
}
