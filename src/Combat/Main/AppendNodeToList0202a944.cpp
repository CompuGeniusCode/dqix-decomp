#include <globaldefs.h>

struct IndexList_0202a9ac;
struct IndexNode_0202a9ac;
struct IndexNode_0202a9ac* GetNodeAtIndex(struct IndexList_0202a9ac* list, int index);

struct ListNode0202a944 {
    int type;
    char pad0[0x30];
    struct ListNode0202a944* next;
    char pad1[0x4];
    unsigned char flag;
    char pad2[0xB];
    void* owner;
};

struct ListHead0202a944 {
    char pad0[0x44];
    struct ListNode0202a944* head;
    char pad1[0x12];
    unsigned short count;
};

// USA: func_0202a944
ARM void AppendNodeToList0202a944(struct ListHead0202a944* list, struct ListNode0202a944* node) {
    node->next = 0;
    if (list->count == 0) {
        list->head = node;
        node->flag = 0;
        list->count = 1;
    } else {
        struct ListNode0202a944* tail = (struct ListNode0202a944*)GetNodeAtIndex((struct IndexList_0202a9ac*)list, list->count - 1);
        if (tail != 0) {
            tail->next = node;
            node->flag = (unsigned char)list->count;
            list->count = list->count + 1;
        }
    }
    if (node->type == 1) {
        node->owner = list;
    }
}
