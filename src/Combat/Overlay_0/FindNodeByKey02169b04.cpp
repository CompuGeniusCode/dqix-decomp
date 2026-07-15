#include <globaldefs.h>

struct Node02169b04 {
    int key;
    struct Node02169b04* next;
};
struct List02169b04 {
    char pad[8];
    struct Node02169b04* head;
};

// USA: func_ov000_02169b04
ARM struct Node02169b04* FindNodeByKey02169b04(struct List02169b04* list, int key) {
    struct Node02169b04* node = list->head;
    while (node) {
        if (node->key == key) return node;
        node = node->next;
    }
    return NULL;
}
