#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"

extern "C" int ResolvePackLv5ArchiveForPath(char* path, char* outMemberName, char* outArchivePath);
extern const char strDataStr_02165745[];

extern int data_ov001_021658e0[];

struct EventAssetQueue {
    char unknown0[0x88];
    int queuedCount;
};
extern EventAssetQueue data_ov001_021658b8;

// Queues one named asset and records the handle in slot <slotIndex> of data_ov001_021658e0,
// bumping the queued count that func_ov001_0215ed2c resets and func_ov001_0215ed74 resumes
// from.
// ResolvePackLv5ArchiveForPath decides where the asset lives: a path containing "chara/p_" is taken from
// data/pack_lv5/chara_pc.gp2 with the "chara/" prefix stripped, a path containing ".mon" from
// data/pack_lv5/enemy.gp2 by basename, and anything else is a plain file at data/<path>. That
// splitter also holds "chara\p_", but the strstr for it throws its result away, so a
// backslash-separated path never reaches chara_pc.gp2.
// Calling these event assets rests on ov001 being the event overlay and nothing else.
extern "C" ARM void QueueEventAssetLoad(char* path, int slotIndex) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char loadPath[0x50];
    char archivePath[0x50];
    if (ResolvePackLv5ArchiveForPath(path, loadPath, archivePath) != 0) {
        data_ov001_021658e0[slotIndex] = loader->QueueLoadFileInGP2(archivePath, loadPath, NULL);
    } else {
        sprintf(loadPath, strDataStr_02165745, path);
        data_ov001_021658e0[slotIndex] = loader->QueueLoadFile(loadPath, NULL);
    }
    data_ov001_021658b8.queuedCount += 1;
}
