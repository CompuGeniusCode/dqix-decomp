#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetData02104304Field4(void);
extern "C" void func_020301c8(int, int);
struct BattleStruct* GetBattleStruct();
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void SetByteField0x253(void* obj);
void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord020466f4 {
    unsigned int flags;
};
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);

struct Struct020d9fc8 {
    char pad[0xc];
    int arr[1];
};

// USA: func_020d9fc8
ARM void ClearHandleArrayAndFinalize020d9fc8(struct Struct020d9fc8* p) {
    int x = GetData02104304Field4();
    int i;
    for (i = 0; i < 1; i++) {
        if (p->arr[i] != -1) {
            func_020301c8(x, p->arr[i]);
            p->arr[i] = -1;
        }
    }
    SetByteField0x253(GetCombatantAtField0x397c(GetBattleStruct()));
    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x1e);
    *((unsigned char*)p + 1) = 1;
}
