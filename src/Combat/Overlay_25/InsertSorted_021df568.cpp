#include <globaldefs.h>

struct Node021df568 {
    int key;
    struct Node021df568* prev;
    struct Node021df568* next;
};

// USA: func_ov025_021df568
ARM struct Node021df568* InsertSorted_021df568(struct Node021df568* head, struct Node021df568* newNode) {
    struct Node021df568* cur = head;
    while (cur != NULL) {
        if (newNode->key < cur->key) {
            if (cur->prev != NULL) {
                cur->prev->next = newNode;
            }
            newNode->next = cur;
            newNode->prev = cur->prev;
            cur->prev = newNode;
            if (cur == head) {
                head = newNode;
            }
            return head;
        }
        if (cur->next == NULL) {
            cur->next = newNode;
            newNode->prev = cur;
            return head;
        }
        cur = cur->next;
    }
    return head;
}
