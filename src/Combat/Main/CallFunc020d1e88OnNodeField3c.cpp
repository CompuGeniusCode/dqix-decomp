#include <globaldefs.h>

int EnqueueEvent0x6Sub4(int, int);

struct Node020bc1ac { unsigned char pad[0x3c]; unsigned char field3c; };
struct Obj020bc1ac { struct Node020bc1ac* node; };

// USA: func_020bc1ac
ARM void CallFunc020d1e88OnNodeField3c(struct Obj020bc1ac* obj, int arg) {
    if (*(int*)obj == 0) return;
    EnqueueEvent0x6Sub4(obj->node->field3c, arg);
}
