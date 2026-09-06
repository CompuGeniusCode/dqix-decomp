#include <globaldefs.h>

struct Variant02030b0c { int tag; int u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct SearchNode0207afbc;
SearchNode0207afbc* FindNodeByName0207afbc(SearchNode0207afbc** head, const char* name);

struct S02037418;
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(struct S02037418* obj, int val);

extern int data_02108e40;

struct NodeFC0207a464 { char pad[0xfc]; unsigned char field_fc; };

// USA: func_0207a464
ARM int ApplyVariantToNamedNode0207a464(struct Variant02030b0c* arg0) {
    char* base = (char*)&data_02108e40;
    SearchNode0207afbc** head = *(SearchNode0207afbc***)(base + 8);
    if (head == NULL) return 0;
    const char* name = *(const char**)(base + 4);
    if (name == NULL) return 0;
    NodeFC0207a464* node = (NodeFC0207a464*)FindNodeByName0207afbc(head, name);
    if (node == NULL) return 0;
    int v = _ZNK6Script9Parameter5ToIntEv(arg0);
    node->field_fc = v;
    _ZN8Object3D17SetInheritedAlphaEi((struct S02037418*)node, v);
    return 1;
}
