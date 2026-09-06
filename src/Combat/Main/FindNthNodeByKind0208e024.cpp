#include <globaldefs.h>

struct Node0208e024 {
    unsigned short field0;
    unsigned short low : 9;
    unsigned short kind : 6;
    unsigned short high : 1;
    int field4;
    struct Node0208e024* next;
};

struct List0208e024 {
    struct Node0208e024* head;
};

// USA: func_0208e024
ARM struct Node0208e024* FindNthNodeByKind0208e024(struct List0208e024* list, int kind, int index) {
    struct Node0208e024* n;
    unsigned char count;
    n = list->head;
    if (n == NULL) {
        return NULL;
    }
    count = 0;
    while (n != NULL) {
        if (kind == n->kind) {
            if (count == index) {
                return n;
            }
            count++;
        }
        n = n->next;
    }
    return n;
}
