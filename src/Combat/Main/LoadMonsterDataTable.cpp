#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" void func_0206f01c(void* a, void* b, void* data, unsigned int size);

extern char strDataPrmMonDataGp2;        // "data/prm/mon_data.gp2"
extern char strMonDataLgNat;  // "mon_data_<LG>.nat"

// USA: func_0206efd8
// The two literals are the whole identification: the archive is data/prm/mon_data.gp2 and the
// entry pulled out of it is mon_data_<LG>.nat. <LG> is not part of the stored filename --
// ExtractFileFromGP2 runs the inner name through StringReplaceLanguageTag first, which is how one
// archive serves En/Fr/Es from the same code path. The .gp2 itself is a GPC archive (see
// include/Filesystem/GPC.h): header and file info are decompressed first, then the named entry.
//
// The lock pair belongs to BackgroundLoader, not to this file. AddLock does nothing unless tasks
// are already pending; otherwise it shifts a bit into processLockBits_ so nested locks unwind in
// order, and the last RemoveLock is what lets a queued task run again. Presumably the point is to
// keep the queue off the card bus for the duration of this read.
extern "C" ARM void LoadMonsterDataTable(void* a, void* b) {
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* data = ExtractFileFromGP2(&strDataPrmMonDataGp2, &strMonDataLgNat, &size);
    func_0206f01c(a, b, data, size);
    BackgroundLoader::RemoveLockGlobal();
}
