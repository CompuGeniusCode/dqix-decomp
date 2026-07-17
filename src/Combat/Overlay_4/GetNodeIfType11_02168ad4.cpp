#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);

// USA: func_ov004_02168ad4
ARM void* GetNodeIfType11_02168ad4(void* a, int id) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), id);
    if (node) {
        if (ScaleStatsIfType12_021f6f10(node) == 11) return node;
    }
    return NULL;
}
