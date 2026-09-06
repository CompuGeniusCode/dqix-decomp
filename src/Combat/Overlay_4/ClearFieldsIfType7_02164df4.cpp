#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);
extern "C" void func_ov023_021f9ba8(void*, int);
extern "C" void func_ov023_021f9bb8(void*, int);

// USA: func_ov004_02164df4
ARM int ClearFieldsIfType7_02164df4(void* a) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 0xb);
    if (!node) return 0;
    if (ScaleStatsIfType12_021f6f10(node) != 7) return 0;
    func_ov023_021f9ba8(node, 0);
    func_ov023_021f9bb8(node, 0);
    return 0;
}
