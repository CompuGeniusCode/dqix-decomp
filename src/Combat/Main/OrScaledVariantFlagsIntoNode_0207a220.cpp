#include <globaldefs.h>

struct Variant02030b0c { int tag; int u; };
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct SearchNode0207afbc;
SearchNode0207afbc* FindNodeByName0207afbc(SearchNode0207afbc** head, const char* name);

extern int data_02108e40;

struct NodeF00207a220 { char pad[0xf0]; unsigned short flags; };

// USA: func_0207a220  (semantic: OrScaledVariantFlagsIntoNode_0207a220)
extern "C" ARM int func_0207a220(struct Variant02030b0c* arg0, int count) {
    char* base = (char*)&data_02108e40;
    SearchNode0207afbc** head = *(SearchNode0207afbc***)(base + 8);
    if (head == NULL) return 0;
    const char* name = *(const char**)(base + 4);
    if (name == NULL) return 0;
    struct NodeF00207a220* node = (struct NodeF00207a220*)FindNodeByName0207afbc(head, name);
    if (node == NULL) return 0;

    int v = GetIntFromVariant02030b0c(arg0);
    if (v > 8) node->flags |= v;

    if (count >= 2) {
        v = GetIntFromVariant02030b0c(arg0 + 1);
        if (v > 8) node->flags |= v;
        return 1;
    } else {
        return 1;
    }
}
