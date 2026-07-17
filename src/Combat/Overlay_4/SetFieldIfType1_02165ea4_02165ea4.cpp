#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);
extern "C" void func_ov023_021fb27c(void*, int);

// USA: func_ov004_02165ea4
ARM void* SetFieldIfType1_02165ea4_02165ea4(void* a, int key, int v) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), key);
    if (node == NULL) node = NULL;
    else if (ScaleStatsIfType12_021f6f10(node) != 1) node = NULL;
    if (node == NULL) return NULL;
    func_ov023_021fb27c(node, v);
    return node;
}
