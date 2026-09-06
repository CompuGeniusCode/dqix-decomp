#include <globaldefs.h>

#pragma optimize_for_size off

struct Node0221e798 {
    int value;
    int rest;
};

extern "C" THUMB void func_ov031_0221e6e8(int a, int* b);

// USA: func_ov031_0221e798  (semantic: StoreAndForward_0221e798)
extern "C" THUMB void func_ov031_0221e798(Node0221e798* node, int a, int value) {
    node->value = value;
    func_ov031_0221e6e8(a, &node->rest);
}
