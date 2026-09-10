#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

extern "C" struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);

extern "C" void* func_ov025_021e8a54(char* obj);
extern "C" int ResolveCharaArchiveForPath(char* path, char* out2, char* out1);

struct BackgroundLoaderSelf;
struct BackgroundLoaderSelf;
extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int outIds);
extern "C" void func_ov025_021e267c(int combatantId, int modelData, int modelSize, int usesWomanModel);
struct OuenTaskList;
extern "C" void func_ov025_021eb084(struct OuenTaskList* obj, int taskId);

struct OuenLoadContext { char unknown0[0xc]; void* target; };
extern struct OuenLoadContext data_ov025_021ef988;
extern char strDataCharaChrSOuenChr;

struct RoundStepParams {
    char unknown0[8];
    unsigned char targetSelector;
};

struct RoundStepContext { char unknown0[0x10]; void* field0x10; };

struct CharacterRecord { char unknown0[0x49c]; unsigned char usesWomanModel : 1; };

// Takes the already-loaded data/chara/ms_ouen.chr or ws_ouen.chr and applies it to every combatant
// the dispatcher hands back, through func_ov025_021e267c, which swaps the model into the Object3D
// of that combatant while preserving its current animation name and time. The 'm' or 'w' comes from
// one bit at +0x49c of the record hung off the combatant at +0x150, presumably the gender of the
// character. Which combatants come back is decided by the step itself: the byte at +0x8 of the
// parameter block is an index func_ov000_021820bc bounds to 0x3a and looks up in
// data_ov000_0218409c, and the handler it finds fills the eight-entry id array. This is the half
// that finishes what QueueOuenChrForGender queued: at the end it tears the ticket down with
// RemoveTask and func_ov025_021eb084 on data_ov025_021ef988.
extern "C" ARM int ApplyOuenModelToCombatants(struct RoundStepParams* p, struct RoundStepContext* ctx, int unusedR2, void* dispatchObj) {
    struct BattleStruct* bs = GetBattleStruct();
    int handle = (int)BackgroundLoader::GetInstance();
    func_ov025_021e8a54((char*)data_ov025_021ef988.target);

    int cid = *(unsigned short*)((char*)ctx->field0x10 + 0x20);
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(bs, cid);
    struct CharacterRecord* characterRecord = *(struct CharacterRecord**)((char*)combatant + 0x150);
    char ch = 'm';
    if (characterRecord->usesWomanModel == 1) {
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
        id = ((BackgroundLoader*)((struct BackgroundLoaderSelf*)handle))->GetLoadedFileInArchive((const char*)(name1), (const char*)(name2), (void**)(&out1), (unsigned int*)(&out2));
    } else {
        id = ((BackgroundLoader*)((struct BackgroundLoaderSelf*)handle))->GetLoadedFileByName((const char*)(buf), (void**)(&out1), (unsigned int*)(&out2));
    }

    if (out1 != 0) {
        int ids[8];
        int count = func_ov000_021820bc(dispatchObj, (int)ctx, p->targetSelector, (int)&ids[0]);
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                func_ov025_021e267c(ids[i], out1, out2, 0);
            }
        }
    }

    ((BackgroundLoader*)(handle))->RemoveTask((int)(id));
    func_ov025_021eb084((struct OuenTaskList*)data_ov025_021ef988.target, id);
    return 1;
}
