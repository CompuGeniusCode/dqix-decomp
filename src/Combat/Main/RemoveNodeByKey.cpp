#include <globaldefs.h>

struct KeyNode {
    unsigned short key;
    char unk[0x32];
    struct KeyNode* next;
};

struct KeyNodeOwner {
    char unk[0xa8];
    struct KeyNode* head;
};

// USA: func_02037b44
ARM void RemoveNodeByKey(struct KeyNodeOwner* owner, int key) {
    struct KeyNode* curr = owner->head;
    struct KeyNode* prev = 0;
    while (curr != 0) {
        if (curr->key == key) {
            if (prev != 0) {
                prev->next = curr->next;
            } else {
                owner->head = curr->next;
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
