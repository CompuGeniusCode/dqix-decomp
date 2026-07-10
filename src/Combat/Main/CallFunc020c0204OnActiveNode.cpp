#include <globaldefs.h>

extern "C" void func_020c0204(void* dst, int value, int arg);

struct Node020bc180 { unsigned char pad[0x2c]; unsigned char state; };
struct Obj020bc180 { struct Node020bc180* node; };

// USA: func_020bc180
ARM void CallFunc020c0204OnActiveNode(struct Obj020bc180* obj, int value, int arg) {
    if (*(int*)obj == 0) return;
    if (obj->node->state == 2) return;
    func_020c0204((char*)obj->node + 0x1c, value << 8, arg);
}
