#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);

// USA: func_ov004_02165e70
ARM void* CheckTypeAndReturnNode_02165e70_02165e70(void* a, int key) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), key);
    if (!node) return NULL;
    if (ScaleStatsIfType12_021f6f10(node) != 0x15) return NULL;
    return node;
}
