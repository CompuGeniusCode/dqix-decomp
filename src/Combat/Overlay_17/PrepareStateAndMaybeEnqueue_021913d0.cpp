#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_0202ae18(void);
extern "C" int func_0202c508(void);
extern "C" void* func_02012fe4(void);
void StoreThreeWords_0218f574(int* p, int a, int b, int c);
struct Struct021c1e40;
void InitState66_021c1e40(struct Struct021c1e40* p);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);
extern "C" void func_ov017_021ce400(int a, int b);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

struct Vec3_021913d0 { int x; int y; int z; };

// USA: func_ov017_021913d0  (semantic: PrepareStateAndMaybeEnqueue_021913d0)
extern "C" ARM void func_ov017_021913d0(unsigned char* obj, int count) {
    if (count > 0) {
        unsigned char* r4 = *(unsigned char**)(obj + 0x3000 + 0xba0);
        if (r4[2] == 0) {
            if (r4[0xb] == 0) {
                struct BattleStruct* battle = GetBattleStruct();
                struct CombatantStruct* combatant = GetCombatantWithFlag0x800(battle, 0);
                struct Vec3_021913d0 a = *(struct Vec3_021913d0*)((char*)combatant + 0x44);
                int* dest = (int*)((char*)battle + 0xf60 + 0x7000);
                StoreThreeWords_0218f574(dest, a.x, a.y, a.z);
            }
            InitState66_021c1e40((struct Struct021c1e40*)r4);
            r4[0xb] = (unsigned char)count;
            struct TailList020469b4* list = *(struct TailList020469b4**)(obj + 0x3000 + 0x700);
            AppendNodeToTail(list, (struct TailNode020469b4*)r4);
        }
        func_0202ae18();
        if (func_0202c508()) {
            unsigned short* entry = (unsigned short*)func_02012fe4();
            func_ov017_021ce400(count, (unsigned short)*entry);
        }
    }
}
