#include <globaldefs.h>

struct Node71BC {
    unsigned char _pad0[0x70];
    unsigned int key;              /* 0x70 */
    unsigned char _pad1[8];        /* 0x74 */
    struct Node71BC* prev;         /* 0x7c */
    struct Node71BC* next;         /* 0x80 */
};

struct List71BC {
    struct Node71BC* head;         /* 0x00 */
    struct Node71BC* tail;         /* 0x04 */
};

// USA: func_020c71bc
ARM void InsertNodeSorted(struct List71BC* list, struct Node71BC* newNode) {
    struct Node71BC* node = list->head;
    while (node != 0 && node->key <= newNode->key) {
        if (node == newNode) return;
        node = node->next;
    }
    if (node == 0) {
        struct Node71BC* tail = list->tail;
        if (tail == 0) {
            list->head = newNode;
        } else {
            tail->next = newNode;
        }
        newNode->prev = tail;
        newNode->next = 0;
        list->tail = newNode;
    } else {
        struct Node71BC* prev = node->prev;
        if (prev == 0) {
            list->head = newNode;
        } else {
            prev->next = newNode;
        }
        newNode->prev = prev;
        newNode->next = node;
        node->prev = newNode;
    }
}
