#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "Combat/Main/BattleList.h"

struct HalfwordRecord02052884 {
    char pad[0x20];
    short current;
    short previous;
    short latest;
    short kind;
    short counter;
};

extern "C" float func_ov017_021d6110(void* obj);
extern "C" unsigned int func_ov017_021d60f4(void* obj);
unsigned int GetField0x3b4Value(struct BattleStruct* battleStruct);

// USA: func_ov001_02164004  (semantic: RecordChangeFromTaggedValues_02164004)
extern "C" ARM int func_ov001_02164004(void* obj, int count) {
    float f = func_ov017_021d6110(obj);
    unsigned int extra = 0;
    struct BattleStruct* battle = GetBattleStruct();
    if (count >= 2) {
        extra = func_ov017_021d60f4((char*)obj + 8);
    }
    unsigned short kind = extra * GetField0x3b4Value(battle);
    LightingManager::GetInstance()->BeginFade(4096.0f * f, kind);
    return 1;
}
