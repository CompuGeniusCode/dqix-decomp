#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);
struct Fields021849e0;
void SetFieldConditional_021849e0(struct Fields021849e0* obj, unsigned short val);
struct S021f9c0c;
void* ClearBuffer_021f9c0c(struct S021f9c0c* obj);

// USA: func_ov004_0216b1c4
ARM void* SetFieldAndClearBufferIfType7_0216b1c4(void* a, int id) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), id);
    if (!node) return node;
    int t = ScaleStatsIfType12_021f6f10(node);
    if (t != 7) return (void*)t;
    SetFieldConditional_021849e0((struct Fields021849e0*)a, (unsigned short)id);
    return ClearBuffer_021f9c0c((struct S021f9c0c*)node);
}
