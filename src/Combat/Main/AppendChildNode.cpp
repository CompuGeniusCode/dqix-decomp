#include <globaldefs.h>

struct NodeAAF90 {
    struct NodeAAF90* first;
    char _pad[0xFC];
    struct NodeAAF90* next;
};

// USA: func_0207af90
ARM void AppendChildNode(struct NodeAAF90* parent, struct NodeAAF90* node) {
    struct NodeAAF90* cur = parent->first;
    if (cur == 0) {
        parent->first = node;
        return;
    }
    while (cur->next != 0) {
        cur = cur->next;
    }
    cur->next = node;
}
