#include <globaldefs.h>

struct NodeStruct0220357c { unsigned char pad[8]; unsigned char type; unsigned char flag9; };
struct EntityStruct0220357c { unsigned char pad[0xa4]; NodeStruct0220357c* node; };
struct RootStruct0220357c { unsigned char pad[4]; EntityStruct0220357c* entity; };

extern RootStruct0220357c data_02111304;
ARM int WaitForField44_022034ac(unsigned int* out, void* obj);
extern "C" int func_ov031_0220a594(unsigned int* out, void* obj);
ARM int WaitOrCycle_02203500(unsigned int* out, void* obj);

#pragma optimize_for_size off
// USA: func_ov031_0220357c  (semantic: DispatchByNodeType_0220357c)
extern "C" ARM int func_ov031_0220357c(unsigned int* out) {
    NodeStruct0220357c* node = data_02111304.entity->node;
    if (node) {
        if ((unsigned char)(node->type + 0xf6) <= 1) return WaitForField44_022034ac(out, node);
        if (node->flag9) return func_ov031_0220a594(out, node);
        return WaitOrCycle_02203500(out, node);
    }
    *out = 0;
    return 0;
}
