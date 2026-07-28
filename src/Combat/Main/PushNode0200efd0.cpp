#include <globaldefs.h>

struct Node0200efd0 {
    struct Node0200efd0* next;
    int b;
    int c;
};

extern struct Node0200efd0* data_020f33b0;

// USA: func_0200efd0  (semantic: PushNode0200efd0)
extern "C" ARM void func_0200efd0(int c, int b, struct Node0200efd0* node) {
    node->next = data_020f33b0;
    node->b = b;
    node->c = c;
    data_020f33b0 = node;
}
