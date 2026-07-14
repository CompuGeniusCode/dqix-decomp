#include <globaldefs.h>

struct TaggedValue02030b44 {
    int type;
    union {
        int i;
        float f;
    } value;
};
float GetTaggedValueAsFloat(struct TaggedValue02030b44* v);

struct SearchNode0207afbc;
SearchNode0207afbc* FindNodeByName0207afbc(SearchNode0207afbc** head, const char* name);

extern int data_02108e40;

struct NodeE80207a4c4 { char pad[0xe8]; int e8; int ec; };

// USA: func_0207a4c4
ARM int ApplyScaledVariantsToNode0207a4c4(struct TaggedValue02030b44* values, int count) {
    char* base = (char*)&data_02108e40;
    SearchNode0207afbc** head = *(SearchNode0207afbc***)(base + 8);
    if (head == NULL) return 0;
    const char* name = *(const char**)(base + 4);
    if (name == NULL) return 0;
    NodeE80207a4c4* node = (NodeE80207a4c4*)FindNodeByName0207afbc(head, name);
    if (node == NULL) return 0;
    node->e8 = (int)(4096.0f * GetTaggedValueAsFloat(values));
    if (count < 2) {
        node->ec = node->e8;
    } else {
        node->ec = (int)(4096.0f * GetTaggedValueAsFloat(values + 1));
    }
    return 1;
}
