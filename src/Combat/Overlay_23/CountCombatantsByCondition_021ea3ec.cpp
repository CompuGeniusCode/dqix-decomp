#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_0200f374(void* buf, int n);
extern unsigned char CopyOutRegion0x5718(char* obj, void* dst);
extern "C" void func_ov017_021d6134(void*, int);

struct Obj130_021ea3ec { char pad[0x130]; unsigned short* ptr130; };

// USA: func_ov023_021ea3ec  (semantic: CountCombatantsByCondition_021ea3ec)
extern "C" ARM int func_ov023_021ea3ec(void* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    unsigned char buf[4];
    func_0200f374(buf, 4);
    unsigned char len = CopyOutRegion0x5718((char*)bs, buf);
    int count = 0;
    for (int i = 1; i < len; i++) {
        unsigned char id = buf[i];
        struct Obj130_021ea3ec* c = (struct Obj130_021ea3ec*)GetCombatantWithFlag0x100(bs, id);
        if (c) {
            int val = *(unsigned short*)((char*)c->ptr130 + 4);
            if (val <= 0) count++;
        }
    }
    func_ov017_021d6134(obj, count);
    return 1;
}
