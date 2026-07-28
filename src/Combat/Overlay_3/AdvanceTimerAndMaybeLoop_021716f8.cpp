#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Obj_02172518;
void LoopCallOv017_02172518(struct Obj_02172518* obj, int flag);
int GetField0x3b4Value(struct BattleStruct* battleStruct);
extern "C" void func_0202ae18(void);
extern "C" void func_0202b0f4(void);

struct Obj021716f8 {
    char pad0[0x34c];
    int field34c;
    char pad350[0x724 - 0x350];
    int field724;
    char pad728[4];
    unsigned int field72c;
};

// USA: func_ov003_021716f8  (semantic: AdvanceTimerAndMaybeLoop_021716f8)
extern "C" ARM void func_ov003_021716f8(struct Obj021716f8* obj) {
    unsigned char* b = (unsigned char*)obj;

    if (obj->field724 != 0) {
        int flag = ((unsigned int)obj->field34c >> 31) ? 1 : 0;
        LoopCallOv017_02172518((struct Obj_02172518*)obj, flag);
        b[0] = 3;
    }

    obj->field72c += GetField0x3b4Value(GetBattleStruct());
    if (obj->field72c <= 0xbb8) return;

    func_0202ae18();
    func_0202b0f4();
    b[0] = 4;
}
