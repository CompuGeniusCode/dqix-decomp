#include <globaldefs.h>

struct Node2057f8c {
    int id;
    char unk[0x1e8];
    struct Node2057f8c* next;
};

// USA: func_02057f8c
ARM struct Node2057f8c* FindNodeById02057f8c(void* list, int id) {
    struct Node2057f8c* node = *(struct Node2057f8c**)list;
    while (node != 0) {
        if (id == node->id) {
            return node;
        }
        node = node->next;
    }
    return 0;
}
