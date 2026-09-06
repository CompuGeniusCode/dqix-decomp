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

struct NodeD80207a0c8 { char pad[0xd8]; int d8; int dc; };

// USA: func_0207a0c8
ARM int ApplyScaledVariantsToNode0207a0c8(struct TaggedValue02030b44* values, int count) {
    char* base = (char*)&data_02108e40;
    SearchNode0207afbc** head = *(SearchNode0207afbc***)(base + 8);
    if (head == NULL) return 0;
    const char* name = *(const char**)(base + 4);
    if (name == NULL) return 0;
    NodeD80207a0c8* node = (NodeD80207a0c8*)FindNodeByName0207afbc(head, name);
    if (node == NULL) return 0;
    node->d8 = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(values));
    if (count < 2) {
        node->dc = node->d8;
        return 1;
    }
    node->dc = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(values + 1));
    return 1;
}
