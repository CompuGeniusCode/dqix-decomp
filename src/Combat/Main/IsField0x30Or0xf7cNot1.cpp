#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_02010828(struct BattleStruct* battleStruct);

// USA: func_02068650
ARM int IsField0x30Or0xf7cNot1(struct BattleStruct* battleStruct, void* arg2) {
    signed char v = *(signed char*)((char*)arg2 + 0x30);
    if (v < 0) {
        v = *(signed char*)((char*)func_02010828(battleStruct) + 0xf7c);
    }
    return v != 1;
}
