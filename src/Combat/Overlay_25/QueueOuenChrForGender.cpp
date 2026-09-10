#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

extern "C" struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);

struct Ctx021e8344 { char pad[0xc]; void* target; };
extern struct Ctx021e8344 data_ov025_021ef988;
extern char strDataCharaChrSOuenChr;

extern "C" void* func_ov025_021e8a54(char* obj);
extern "C" int func_ov025_021e25a4(char* buf);
extern "C" void func_ov025_021eb05c(void* ctx, int val);

struct Param021e8344 { char pad[0x10]; void* field0x10; };
struct Inner021e8344 { char pad[0x49c]; unsigned char flag : 1; };

// Queues data/chara/ms_ouen.chr or ws_ouen.chr for the combatant this step is acting on, picking
// 'm' or 'w' from the bit at +0x49c of the record hanging off the combatant's +0x150. ouen is the
// only name under data/chara shipped in both spellings -- 63 ms_ files against one ws_ -- which is
// what makes the character a gender selector; presumably the Japanese for cheering on, but nothing
// in the code says so. func_ov025_021eb05c appends the resulting id to an eight-entry list.
extern "C" ARM int QueueOuenChrForGender(void* unused0, struct Param021e8344* ctx) {
    char buf[0x50];
    (int)BackgroundLoader::GetInstance();
    func_ov025_021e8a54((char*)data_ov025_021ef988.target);
    struct BattleStruct* bs = GetBattleStruct();
    int id = *(unsigned short*)((char*)ctx->field0x10 + 0x20);
    struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, id);
    struct Inner021e8344* c2 = *(struct Inner021e8344**)((char*)c + 0x150);
    char ch = 'm';
    if (c2->flag == 1) {
        ch = 'w';
    }
    sprintf(buf, &strDataCharaChrSOuenChr, ch);
    int r = func_ov025_021e25a4(buf);
    func_ov025_021eb05c(data_ov025_021ef988.target, r);
    return 1;
}
