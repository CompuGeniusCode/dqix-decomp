#include <globaldefs.h>

struct ListHead_021e1da4 {
    void* first;
};

struct Node_021e1da4 {
    struct Node_021e1da4* next;
    char pad[4];
    short f8;
};

// USA: func_ov023_021e1da4
ARM short FindIndexByField8_021e1da4(struct ListHead_021e1da4* head, int val) {
    struct Node_021e1da4* n = (struct Node_021e1da4*)head->first;
    short i;
    if (n == NULL) {
        return -1;
    }
    i = 0;
    while (n != NULL) {
        if (n->f8 == val) {
            return i;
        }
        i = i + 1;
        n = n->next;
    }
    return -1;
}
