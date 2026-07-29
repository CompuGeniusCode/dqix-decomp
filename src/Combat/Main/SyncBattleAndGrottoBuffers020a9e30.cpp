#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/GrottoStruct.h"
#include "System/Memory.h"

// USA: func_020a9e30  (semantic: SyncBattleAndGrottoBuffers020a9e30)
extern "C" ARM int func_020a9e30(void* param) {
    void* obj = param;
    struct BattleStruct* battle = GetBattleStruct();
    VectorizedInvertedMemcpy(obj, (char*)battle + 0x6fcc, 0x200);
    VectorizedInvertedMemcpy((char*)obj + 0x204, (char*)battle + 0x5cd0, 0xa);
    int v = *(int*)((char*)obj + 0x200);
    *(int*)((char*)battle + 0x7000 + 0x1cc) = v;
    struct GrottoStruct* grotto = GetGrottoStruct(battle);
    grotto->unknown_0[3] = (*(int*)((char*)obj + 0x200) & 0x1) != 0;
    char* p2 = (char*)battle + 0x7000;
    *(int*)(p2 + 0x1cc) = 0;
    return 1;
}
