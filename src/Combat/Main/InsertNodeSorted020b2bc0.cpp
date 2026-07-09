#include <globaldefs.h>

struct NodeBC0 {
    char pad0[0x10];
    struct NodeBC0* next;
    char pad14[4];
    unsigned char key;
};

// Forces branches instead of if-conversion for this file's functions.
#pragma optimize_for_size off

// USA: func_020b2bc0
ARM void InsertNodeSorted020b2bc0(struct NodeBC0** list, struct NodeBC0* n) {
    struct NodeBC0* head = *list;
    struct NodeBC0* cur;
    struct NodeBC0* prev;
    struct NodeBC0* p;
    unsigned char nkey;
    if (head == 0) {
        *list = n;
        return;
    }
    cur = head->next;
    prev = head;
    if (cur == 0) {
        if (head->key > n->key) {
            p = n;
            if (p->next != 0) {
                do { p = p->next; } while (p->next != 0);
            }
            p->next = head;
            *list = n;
        } else {
            head->next = n;
        }
    } else {
        if (cur != 0) {
            nkey = n->key;
            do {
                if (cur->key >= nkey) {
                    p = n;
                    if (p->next != 0) {
                        do { p = p->next; } while (p->next != 0);
                    }
                    prev->next = n;
                    p->next = cur;
                    return;
                }
                prev = cur;
                cur = cur->next;
            } while (cur != 0);
        }
        prev->next = n;
    }
}
