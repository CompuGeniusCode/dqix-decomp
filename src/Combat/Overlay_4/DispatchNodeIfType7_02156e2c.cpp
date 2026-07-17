#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);
extern "C" void* func_ov023_021f9bc8(void*);

// USA: func_ov004_02156e2c
ARM int DispatchNodeIfType7_02156e2c(void* a, int key) {
    void* base = func_ov011_021849c8(a);
    void* node = func_ov023_021f6880(base, key);
    if (!node) return -1;
    if (ScaleStatsIfType12_021f6f10(node) != 7) return -1;
    return (int)func_ov023_021f9bc8(node);
}
