#include <globaldefs.h>

struct TaggedValue02030b44 {
    int type;
    union {
        int i;
        float f;
    } value;
};
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

struct SearchNode0207afbc;
SearchNode0207afbc* FindNodeByName0207afbc(SearchNode0207afbc** head, const char* name);

extern int data_02108e40;

struct NodeE00207a2ac { char pad[0xe0]; int e0; int e4; };

// USA: func_0207a2ac
ARM int ApplyScaledVariantsToNode0207a2ac(struct TaggedValue02030b44* values, int count) {
    char* base = (char*)&data_02108e40;
    SearchNode0207afbc** head = *(SearchNode0207afbc***)(base + 8);
    if (head == NULL) return 0;
    const char* name = *(const char**)(base + 4);
    if (name == NULL) return 0;
    NodeE00207a2ac* node = (NodeE00207a2ac*)FindNodeByName0207afbc(head, name);
    if (node == NULL) return 0;
    node->e0 = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(values));
    if (count < 2) {
        node->e4 = node->e0;
        return 1;
    }
    node->e4 = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(values + 1));
    return 1;
}
