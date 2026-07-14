#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_020ae074(void* a);
struct PointerField330_ffd0;
void* GetPointerAt0x330(struct PointerField330_ffd0* obj);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
struct S02046b1c;
int GetField0x0List02046b1c(struct S02046b1c* p);

struct Struct020aca30 { char pad[0x36fc]; void* field0x36fc; };

// USA: func_020aca30
ARM void ProcessSlotEntry020aca30(struct Struct020aca30* a0) {
    struct BattleStruct* battle = GetBattleStruct();
    void* p;
    void* field = a0->field0x36fc;
    p = GetPointerAt0x330((struct PointerField330_ffd0*)battle);
    int headId = GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)field);
    int f0 = GetField0x0List02046b1c((struct S02046b1c*)field);
    if (p == NULL) return;
    if (headId == 0xa) {
        if (*((unsigned char*)f0 + 3) != 0) return;
    }
    func_020ae074(p);
}
