#include <globaldefs.h>

struct ListNode {
    char unknown0[2];
    unsigned char inList;
    char unknown3;
    struct ListNode* next;
};

struct NodeList {
    struct ListNode* head;
    struct ListNode* tail;
};

// Appends a node to a head/tail list. The node header is four bytes ahead of the next pointer:
// byte 0 is the id GetListHeadId (0x02046b24) returns and ResetListNodeHeader sets to -1, byte 1
// is the flag func_02046968 (0x02046968) pops on, byte 2 is the in-list flag this sets.
// Byte 3 is touched only by the head-insert and pop paths - func_020469f8 clears it on the
// head it demotes, func_02046968 sets it on the node that stops the pop - which reads
// like a front-of-list flag but is not established. None of the four is read here.
// The primitive is shared rather than owned: func_ov017_0219bd1c uses it for the gamemain list at
// ctx+0x3000+0x6fc, func_020e3b8c for its own records at mgr+0x3704, so it carries no subject of
// its own. node->next is stored NULL inside each branch and once more after them; that double
// store is in the ROM, at 0x020469d0/0x020469e0 and 0x020469e8.
extern "C" ARM void AppendNodeToTail(struct NodeList* list, struct ListNode* node) {
    if (list->head != NULL && list->tail != NULL) {
        list->tail->next = node;
        list->tail = node;
        node->next = NULL;
    } else {
        list->head = node;
        list->tail = node;
        node->next = NULL;
    }
    node->next = NULL;
    node->inList = 1;
}
