#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov025_021e8a54(char* obj);
extern "C" int ResolveCharaArchiveForPath(char* s, char* out2, char* out1);

struct SearchObj0202ffd8;
struct SearchObj0202ff34;
extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
extern "C" void func_ov025_021e267c(int combatantId, int arg1, int arg2, int flag);
struct RemoveList021eb084;
extern "C" void func_ov025_021eb084(struct RemoveList021eb084* obj, int val);

extern int data_ov025_021ef988;
extern char strData_021eefa0[];

struct Param021e4aac {
    char pad[8];
    unsigned char field8;
    char pad2[3];
    char* field0xc;
};

// Handler thirty of the ov025 command table that starts at 0x021ef544. It prefixes "data/" to the
// file name carried in the command's parameter block at +0xc; ResolveCharaArchiveForPath turns a
// chara_pc or chara_mp name into an archive-plus-member pair against data/pack_lv5/chara_pc.gp2 or
// chara_mp.gp2, and anything else is looked up as a whole path. The blob is then handed to every
// combatant the selector byte at +0x8 picks out, where it is loaded onto their Object3D as a model
// or a motion, and the loader task is released on the way out.
extern "C" ARM int LoadCombatantModelOrMotion(struct Param021e4aac* p, int unused, int unusedR2, void* dispatchObj) {
    GetBattleStruct();
    int handle = (int)BackgroundLoader::GetInstance();
    func_ov025_021e8a54(*(char**)((char*)&data_ov025_021ef988 + 0xc));

    char buf[0x50];
    int n = 0x50;
    unsigned char* d = (unsigned char*)buf;
    unsigned char* s = (unsigned char*)strData_021eefa0;
    do {
        *d = *s;
        d++;
        s++;
    } while (--n);
    strcat(buf, p->field0xc);

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
        int count = func_ov000_021820bc(dispatchObj, unused, p->field8, (int)&ids[0]);
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                func_ov025_021e267c(ids[i], out1, out2, 0);
            }
        }
    }

    ((BackgroundLoader*)(handle))->RemoveTask((int)(id));
    func_ov025_021eb084((struct RemoveList021eb084*)(*(char**)((char*)&data_ov025_021ef988 + 0xc)), id);
    return 1;
}
