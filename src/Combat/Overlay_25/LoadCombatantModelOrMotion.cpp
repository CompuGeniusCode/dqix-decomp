#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov025_021e8a54(char* loadManager);
extern "C" int ResolveCharaArchiveForPath(char* path, char* out2, char* out1);

struct ArchiveLookupLoader;
struct NameLookupLoader;
extern "C" int func_ov000_021820bc(void* dispatchObj, int unused, int index, int handlerArg);
extern "C" void func_ov025_021e267c(int combatantId, int fileData, int fileSize, int animationCallback);
struct ModelLoadManager;
extern "C" void func_ov025_021eb084(struct ModelLoadManager* loadManager, int taskId);

extern int data_ov025_021ef988;
extern char strData_021eefa0[];

struct LoadCommandParams {
    char unknown0[8];
    unsigned char combatantSelector;
    char unknown9[3];
    char* fileName;
};

// Handler thirty of the ov025 command table that starts at 0x021ef544. It prefixes "data/" to the
// file name carried in the command parameter block at +0xc; ResolveCharaArchiveForPath turns a
// chara_pc or chara_mp name into an archive-plus-member pair against data/pack_lv5/chara_pc.gp2 or
// chara_mp.gp2, and anything else is looked up as a whole path. The blob is then handed to every
// combatant the selector byte at +0x8 picks out, where it is loaded onto their Object3D as a model
// or a motion, and the loader task is released on the way out. The last argument of
// func_ov025_021e267c is the animation callback Object3D::LoadFromCCHROrCMOTArchive takes, null on
// this path; func_ov025_021eb084 then drops the task id out of the count-prefixed short array at
// +0x582 of the ov025 object the globals hold at +0xc, which is also where the allocator and the
// log list used by the per-combatant load live.
extern "C" ARM int LoadCombatantModelOrMotion(struct LoadCommandParams* p, int unused, int unusedR2, void* dispatchObj) {
    GetBattleStruct();
    int handle = (int)BackgroundLoader::GetInstance();
    func_ov025_021e8a54(*(char**)((char*)&data_ov025_021ef988 + 0xc));

    char buf[0x50];
    int bytesLeft = 0x50;
    unsigned char* dest = (unsigned char*)buf;
    unsigned char* source = (unsigned char*)strData_021eefa0;
    do {
        *dest = *source;
        dest++;
        source++;
    } while (--bytesLeft);
    strcat(buf, p->fileName);

    char name1[0x50];
    char name2[0x50];
    int out1 = 0;
    int out2;
    int id;
    if (ResolveCharaArchiveForPath(buf, name1, name2)) {
        id = ((BackgroundLoader*)((struct ArchiveLookupLoader*)handle))->GetLoadedFileInArchive((const char*)(name1), (const char*)(name2), (void**)(&out1), (unsigned int*)(&out2));
    } else {
        id = ((BackgroundLoader*)((struct NameLookupLoader*)handle))->GetLoadedFileByName((const char*)(buf), (void**)(&out1), (unsigned int*)(&out2));
    }

    if (out1 != 0) {
        int ids[8];
        int count = func_ov000_021820bc(dispatchObj, unused, p->combatantSelector, (int)&ids[0]);
        if (count > 0) {
            for (int combatantIndex = 0; combatantIndex < count; combatantIndex++) {
                func_ov025_021e267c(ids[combatantIndex], out1, out2, 0);
            }
        }
    }

    ((BackgroundLoader*)(handle))->RemoveTask((int)(id));
    func_ov025_021eb084((struct ModelLoadManager*)(*(char**)((char*)&data_ov025_021ef988 + 0xc)), id);
    return 1;
}
