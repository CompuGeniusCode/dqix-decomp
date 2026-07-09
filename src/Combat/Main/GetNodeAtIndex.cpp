#include <globaldefs.h>

struct IndexNode_0202a9ac {
    char unk[0x34];
    struct IndexNode_0202a9ac* next;
};

struct IndexList_0202a9ac {
    char unk[0x44];
    struct IndexNode_0202a9ac* head;
    char unk2[0x12];
    unsigned short count;
};

// USA: func_0202a9ac
ARM struct IndexNode_0202a9ac* GetNodeAtIndex(struct IndexList_0202a9ac* list, int index) {
    struct IndexNode_0202a9ac* node;
    int i;
    if (index < 0 || list->count <= index) {
        return 0;
    }
    node = list->head;
    for (i = 0; i < index; i++) {
        if (node == 0) {
            return 0;
        }
        node = node->next;
    }
    return node;
}
