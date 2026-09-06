#include <globaldefs.h>
void* GetPtrField0x2a04(struct BattleStruct*);
#include "Combat/Main/BattleList.h"


// USA: func_02068650
ARM int IsField0x30Or0xf7cNot1(struct BattleStruct* battleStruct, void* arg2) {
    signed char v = *(signed char*)((char*)arg2 + 0x30);
    if (v < 0) {
        v = *(signed char*)((char*)GetPtrField0x2a04((struct BattleStruct*)(battleStruct)) + 0xf7c);
    }
    return v != 1;
}
