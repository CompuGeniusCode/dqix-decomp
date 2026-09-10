#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

extern "C" struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);

extern "C" void* func_ov025_021e8a54(char* obj);
extern "C" int ResolveCharaArchiveForPath(char* s, char* out2, char* out1);

struct SearchObj0202ffd8;
struct SearchObj0202ff34;
extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
extern "C" void func_ov025_021e267c(int combatantId, int arg1, int arg2, int flag);
struct RemoveList021eb084;
extern "C" void func_ov025_021eb084(struct RemoveList021eb084* obj, int val);

struct Ctx021e83c4 { char pad[0xc]; void* target; };
extern struct Ctx021e83c4 data_ov025_021ef988;
extern char strDataCharaChrSOuenChr;

struct Param021e83c4 {
    char pad[8];
    unsigned char field8;
};

struct Ctx1021e83c4 { char pad[0x10]; void* field0x10; };

struct Inner021e83c4 { char pad[0x49c]; unsigned char flag : 1; };

// Takes the already-loaded data/chara/ms_ouen.chr or ws_ouen.chr and applies it to every combatant
// the dispatcher hands back, through func_ov025_021e267c, which swaps the model into that
// combatant's Object3D while preserving its current animation name and time. The 'm' or 'w' comes
// from a bit at +0x49c of the record hung off the combatant at +0x150, presumably the character's
// gender. This is the half that finishes what QueueOuenChrForGender queued: at the end it tears the
// ticket down with RemoveTask and func_ov025_021eb084 on data_ov025_021ef988.
extern "C" ARM int ApplyOuenModelToCombatants(struct Param021e83c4* p, struct Ctx1021e83c4* ctx, int unusedR2, void* dispatchObj) {
    struct BattleStruct* bs = GetBattleStruct();
    int handle = (int)BackgroundLoader::GetInstance();
    func_ov025_021e8a54((char*)data_ov025_021ef988.target);

    int cid = *(unsigned short*)((char*)ctx->field0x10 + 0x20);
    struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, cid);
    struct Inner021e83c4* c2 = *(struct Inner021e83c4**)((char*)c + 0x150);
    char ch = 'm';
    if (c2->flag == 1) {
        ch = 'w';
    }

    char buf[0x50];
    sprintf(buf, &strDataCharaChrSOuenChr, ch);

    char name1[0x50];
    char name2[0x50];
    int out1 = 0;
    int out2;
    int id;
    if (ResolveCharaArchiveForPath(buf, name1, name2)) {
        id = ((BackgroundLoader*)((struct SearchObj0202ffd8*)handle))->GetLoadedFileInArchive((const char*)(name1), (const char*)(name2), (void**)(&out1), (unsigned int*)(&out2));
    } else {
        id = ((BackgroundLoader*)((struct SearchObj0202ff34*)handle))->GetLoadedFileByName((const char*)(buf), (void**)(&out1), (unsigned int*)(&out2));
    }

    if (out1 != 0) {
        int ids[8];
        int count = func_ov000_021820bc(dispatchObj, (int)ctx, p->field8, (int)&ids[0]);
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                func_ov025_021e267c(ids[i], out1, out2, 0);
            }
        }
    }

    ((BackgroundLoader*)(handle))->RemoveTask((int)(id));
    func_ov025_021eb084((struct RemoveList021eb084*)data_ov025_021ef988.target, id);
    return 1;
}
