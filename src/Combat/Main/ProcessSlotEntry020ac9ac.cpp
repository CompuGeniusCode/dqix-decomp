#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_02012fe4(struct BattleStruct* battleStruct);
struct PointerField330_ffd0;
void* GetPointerAt0x330(struct PointerField330_ffd0* obj);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
struct S02046b1c;
int GetField0x0List02046b1c(struct S02046b1c* p);
int CheckField0x14Or0x20Positive(int* obj);
extern "C" void func_020ad61c(void* p);
extern "C" void func_ov017_02193dc4(void* p);

struct Struct020ac9ac { char pad[0x36fc]; void* field0x36fc; };

// USA: func_020ac9ac  (semantic: ProcessSlotEntry020ac9ac)
extern "C" ARM void func_020ac9ac(struct Struct020ac9ac* a0) {
    struct BattleStruct* battle = GetBattleStruct();
    void* p;
    int headId;
    void* field = a0->field0x36fc;
    func_02012fe4(battle);
    p = GetPointerAt0x330((struct PointerField330_ffd0*)battle);
    headId = GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)field);
    int f0 = GetField0x0List02046b1c((struct S02046b1c*)field);
    if (p == NULL) return;
    if (headId == 0xa) {
        if (*((unsigned char*)f0 + 3) != 0) return;
    }
    if (headId == 3) {
        if (CheckField0x14Or0x20Positive((int*)a0) == 0) return;
    }
    func_020ad61c(p);
    func_ov017_02193dc4(p);
}
