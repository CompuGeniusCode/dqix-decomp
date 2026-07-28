#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetGlobalField0x1c020421a0(void);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned short func_ov023_021f6f10(void*);
extern "C" void* func_ov023_021fad18(void* obj);
void SetByte0x7f70(void* obj, unsigned char value);

// USA: func_ov004_0216e828  (semantic: SyncFieldPtrsAndResetByte_0216e828)
extern "C" ARM int func_ov004_0216e828(void* a) {
    void* base = func_ov011_021849c8(a);
    int g = GetGlobalField0x1c020421a0();
    void* node = func_ov023_021f6880(base, 0xa);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 0xa) return 0;
    void* result = func_ov023_021fad18(node);
    if (result) {
        *(void**)((char*)g + 0x2d8) = result;
        int tmp = *(int*)((char*)result + 0x3c);
        if (tmp) {
            *(int*)((char*)g + 0x2e0) = tmp;
        }
    }
    SetByte0x7f70(GetBattleStruct(), 0);
    return 0;
}
