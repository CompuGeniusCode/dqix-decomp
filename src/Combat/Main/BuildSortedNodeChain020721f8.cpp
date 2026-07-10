#include <globaldefs.h>

struct SortNode020721f8 {
    unsigned char pad0[0x1a];
    short sortKey;
    struct SortNode020721f8* next;
};

struct SortList020721f8 {
    struct SortNode020721f8* head;
};

extern "C" struct SortNode020721f8* func_02072238(struct SortList020721f8* list, int afterKey);

// USA: func_020721f8
ARM void BuildSortedNodeChain020721f8(struct SortList020721f8* list) {
    struct SortNode020721f8* node;
    list->head = func_02072238(list, -1);
    if (list->head == NULL) return;
    node = list->head;
    while (node != NULL) {
        struct SortNode020721f8* next = func_02072238(list, node->sortKey);
        node->next = next;
        node = next;
    }
}
