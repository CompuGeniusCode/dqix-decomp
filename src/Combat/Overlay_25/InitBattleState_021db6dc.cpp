#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Foo02033b58;
void SetByteSavingPrevious(struct Foo02033b58* p, unsigned char v);
void ClearFlag320_02195540(unsigned char* obj);
int GetGlobalField0x1c020421a0(void);
void InitQueueStruct_021ed124(unsigned char* obj);
void SetField_021e8a4c(char* obj, int v);
void SetFieldNeg1_021e8d14(void* obj);
void ResetFields_021df9b0(void* obj);
void Init021eed58(char* obj);

extern "C" ARM int func_ov017_0218b5b0(void);
extern "C" ARM void func_ov025_021e88d8(void* obj);
extern "C" ARM void func_ov025_021dfbfc(void* obj);
extern "C" int func_ov000_0215ec1c(void* obj, short* buf, int max, int start);

// USA: func_ov025_021db6dc  (semantic: InitBattleState_021db6dc)
extern "C" ARM void func_ov025_021db6dc(void* arg) {
    char* obj = (char*)arg;
    struct BattleStruct* bs = GetBattleStruct();
    int g = GetGlobalField0x1c020421a0();
    int handle = func_ov017_0218b5b0();

    func_ov025_021e88d8(obj + 0x2a8);
    SetField_021e8a4c(obj + 0x2a8, *(int*)(obj + 0x29c));
    SetFieldNeg1_021e8d14(obj + 0x2a8);
    ResetFields_021df9b0(obj + 0x5ab0);
    Init021eed58(obj + 0xb30);
    *(int*)(obj + 0xeb0) = 0;
    ClearFlag320_02195540((unsigned char*)handle);
    *(unsigned char*)((char*)g + 0x19be) = 1;
    *(unsigned char*)(*(char**)(obj + 0x29c) + 0x8e49) = 0;
    *(unsigned char*)(*(char**)(obj + 0x2a0) + 0x35) = 0;
    func_ov025_021dfbfc(obj);

    short buf[16];
    int n = 0;
    n = n + func_ov000_0215ec1c(*(void**)(obj + 0x29c), buf, 0x10, n);
    for (int i = 0; i < n; i++) {
        struct CombatantStruct* c = GetCombatantFromList(bs, buf[i]);
        if (c != 0) {
            int f = *(int*)((char*)c->currentStats + 0x14);
            if (!(f & 1)) {
                SetByteSavingPrevious((struct Foo02033b58*)c, 0);
            }
        }
    }

    InitQueueStruct_021ed124((unsigned char*)(obj + 0x890));
    *(int*)(obj + 0xeac) = 1;
    *(unsigned char*)(obj + 0x6fd5) = 0;
}
