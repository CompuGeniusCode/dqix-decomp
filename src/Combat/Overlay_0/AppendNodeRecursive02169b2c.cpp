#include <globaldefs.h>

struct Node02169b2c {
    char pad[4];
    struct Node02169b2c* next;
};

// USA: func_ov000_02169b2c
ARM void AppendNodeRecursive02169b2c(struct Node02169b2c* node, struct Node02169b2c* newNode) {
    if (node->next == NULL) {
        node->next = newNode;
        newNode->next = NULL;
        return;
    }
    AppendNodeRecursive02169b2c(node->next, newNode);
}
