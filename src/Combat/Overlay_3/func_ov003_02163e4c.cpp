#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
void AddPositiveField150EntriesToMap_021b6bb8(int combatantId);
extern "C" int func_ov017_021b6d60(int a, void* buf);
extern "C" void func_02086778(void* map, void* buf, int c, int d);

// USA: func_ov003_02163e4c  (semantic: AdvanceTargetSearchStep_02163e4c)
extern "C" ARM void func_ov003_02163e4c(char* obj) {
    unsigned char step = obj[0x4a4];
    if (step == 0) {
        char buf[0x23c];
        struct BattleStruct* bs = GetBattleStruct();
        void* map = GetPtrField0x2a04(bs);
        short id = *(short*)(obj + 0x400 + 0x82);
        struct CombatantStruct* c = GetCombatantWithFlag0x800(bs, id);
        if (c == NULL) {
            obj[0x4a3] = 0x10;
            return;
        }
        unsigned char* field150 = (unsigned char*)GetFieldAt0x150((unsigned char*)c);
        if (field150 == NULL) {
            obj[0x4a3] = 0x10;
            return;
        }
        *(short*)(obj + 0x400 + 0x84) = 0xd;
        short v54 = *(short*)(field150 + 0x400 + 0x54);
        if (v54 > 0) {
            *(short*)(obj + 0x400 + 0x86) = 0xe;
        }
        AddPositiveField150EntriesToMap_021b6bb8(*(short*)(obj + 0x400 + 0x82));
        func_ov017_021b6d60(*(short*)(obj + 0x400 + 0x82), buf);
        func_02086778(map, buf, 0, 0);
        short sv = (buf[0] << 26) >> 26;
        *(short*)(obj + 0x400 + 0x80) = sv;
        obj[0x4a4] = (unsigned char)obj[0x4a4] + 1;
        *(int*)(obj + 0x464) |= 8;
        return;
    }
    if (step != 1) return;
    *(short*)(obj + 0x400 + 0x84) = 2;
    *(int*)(obj + 0x464) |= 8;
    obj[0x4a3] = 1;
    obj[0x4a4] = 0;
}
