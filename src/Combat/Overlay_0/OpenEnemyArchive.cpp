#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"

extern char strDataPackLv5EnemyGp2_02183a2f[];
extern char fileStagingBuffer[];

// Opens data/pack_lv5/enemy.gp2 and reads only its header and inner-file index into the shared
// staging buffer, returning the size. The archive is 15.8 MB of per-enemy members named b###a.bact,
// .cchr and .cmot alongside effect/*.chr, so this is the battle overlay's handle on enemy model and
// animation data rather than a load of any one enemy. The flag argument drops every outstanding
// background allocation and takes the loader lock without ever releasing it - the caller owns that.
extern "C" ARM unsigned int OpenEnemyArchive(void* unused, GPCReadPair* readPair, int flag) {
    unsigned int length;
    if (flag) {
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
    }
    readPair->ZeroInitialize();
    LoadAndDecompressGPCHeaderAndInnerFileInfo(&readPair->pGPCFile, readPair->machine,
        strDataPackLv5EnemyGp2_02183a2f, fileStagingBuffer, length, 0x30000, false, NULL);
    return length;
}
