#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int IsField8Bit19Set(unsigned int* obj);
void* GetPtrField0x2a04(struct BattleStruct* battleStruct);

struct KeyMap020a0a08;
int DecrementKeyValue020a0a08(struct KeyMap020a0a08* map, int key, int amount);

int LoadBattleBlock020ac4c0(void* dst);

struct S_a0504;
void AddClamped7BitField(struct S_a0504* p, unsigned int amount);

int CopyInBattleField0x7540(void* src);

// USA: func_020dddcc
ARM int TryDecrementAndAdjustField(void* obj) {
    char local[0xb0];
    if (!IsField8Bit19Set((unsigned int*)obj)) {
        return 0;
    }
    struct BattleStruct* battle = GetBattleStruct();
    void* ptr = GetPtrField0x2a04(battle);
    short key = *(short*)((char*)obj + 0x18);
    if (!DecrementKeyValue020a0a08((struct KeyMap020a0a08*)ptr, key, 1)) {
        return 0;
    }
    int field8 = *(int*)((char*)obj + 0x8);
    if ((unsigned int)field8 >> 31) {
        LoadBattleBlock020ac4c0(local);
        AddClamped7BitField((struct S_a0504*)local, 1);
        CopyInBattleField0x7540(local);
    }
    return 1;
}
