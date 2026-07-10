#include <globaldefs.h>

extern "C" void func_020d1e88(int value, int arg);

struct Node020bc1ac { unsigned char pad[0x3c]; unsigned char field3c; };
struct Obj020bc1ac { struct Node020bc1ac* node; };

// USA: func_020bc1ac
ARM void CallFunc020d1e88OnNodeField3c(struct Obj020bc1ac* obj, int arg) {
    if (*(int*)obj == 0) return;
    func_020d1e88(obj->node->field3c, arg);
}
