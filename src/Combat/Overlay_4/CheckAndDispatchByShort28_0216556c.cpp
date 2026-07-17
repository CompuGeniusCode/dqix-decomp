#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetWord0x0(int* obj);
int CheckField0x14Or0x20Positive(int* obj);
extern char* data_ov004_02171010;
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);
struct Obj021f9bb0;
unsigned int GetShort28_021f9bb0(struct Obj021f9bb0* obj);
extern "C" void func_ov004_021636b0(void* a1, void* a2);

// USA: func_ov004_0216556c
ARM int CheckAndDispatchByShort28_0216556c(void* a1) {
    if (*(unsigned char*)(data_ov004_02171010 + 0x1000 + 0x8f4) == 0) return 0;
    if (CheckField0x14Or0x20Positive((int*)GetWord0x0((int*)GetBattleStruct())) != 0) return 0;

    {
        char* base = data_ov004_02171010;
        unsigned char b = *(unsigned char*)(base + 0x1000 + 0x8fd);
        unsigned char* target = (unsigned char*)(base + 0xfd + 0x1800);
        if (b != 0) {
            *target = 0;
            return 0;
        }
    }

    void* obj = func_ov023_021f6880(func_ov011_021849c8(a1), 0xa);
    if (obj == NULL) return 0;
    if (ScaleStatsIfType12_021f6f10(obj) != 7) return 0;

    unsigned int idx = GetShort28_021f9bb0((struct Obj021f9bb0*)obj);
    void* ptr = (void*)(idx * 0x1c4 + (data_ov004_02171010 + 1 + 0xb00));
    func_ov004_021636b0(a1, ptr);
    return 0;
}
