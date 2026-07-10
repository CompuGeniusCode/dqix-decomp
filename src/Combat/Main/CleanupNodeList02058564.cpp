#include <globaldefs.h>

void* Field0x1cCall0207ecd4OrNull(void* obj);
void* Field0x1cCall0207ecf8OrNull(void* obj);

struct Node02058564 {
    unsigned char pad[0x1ec];
    struct Node02058564* next;   // 0x1ec
};

struct NodeList02058564 {
    struct Node02058564* head;   // 0x0
    int count;                   // 0x4
};

// USA: func_02058564
ARM void CleanupNodeList02058564(struct NodeList02058564* list) {
    struct Node02058564* node;
    if (list->count <= 0) return;
    node = list->head;
    while (node != NULL) {
        Field0x1cCall0207ecd4OrNull(node);
        Field0x1cCall0207ecf8OrNull(node);
        node = node->next;
    }
}
