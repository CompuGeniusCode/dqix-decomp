#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);
extern "C" void func_ov023_021f9ba8(void*, int);
extern "C" int func_ov023_021f98e0(void*, void*);

// USA: func_ov004_0216b338
ARM int SetFieldsIfType7_0216b338(void* a, int id, int val) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), id);
    if (!node) return (int)node;
    int t = ScaleStatsIfType12_021f6f10(node);
    if (t != 7) return t;
    if (!node) return t;
    func_ov023_021f9ba8(node, (unsigned short)val);
    return func_ov023_021f98e0(node, a);
}
