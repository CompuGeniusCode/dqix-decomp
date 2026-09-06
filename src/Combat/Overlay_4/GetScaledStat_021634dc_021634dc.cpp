#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);
struct Obj021f9bb0;
unsigned int GetShort28_021f9bb0(struct Obj021f9bb0* obj);

// USA: func_ov004_021634dc
ARM int GetScaledStat_021634dc_021634dc(void* a) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 0xa);
    if (!node) return 0;
    if (ScaleStatsIfType12_021f6f10(node) != 7) return 0;
    short s = *(short*)((char*)node + 0x5c);
    return GetShort28_021f9bb0((struct Obj021f9bb0*)node) + (s << 3);
}
