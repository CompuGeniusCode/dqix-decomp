#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

void* LoadFileIntoMemory(const char* path, void* dest, unsigned int* outSize);
extern "C" void func_02070a30(void*, void*, void*);

extern char strDataPrmMonBtldataNat;  // "data/prm/mon_btldata.nat"
extern char fileStagingBuffer;

// USA: func_020709ec
// The only file path in this function's literal pool is "data/prm/mon_btldata.nat". Note this one
// is a bare .nat, not a .gp2, so it is read straight in rather than pulled out of an archive, and
// it has no <LG> tag -- the battle numbers are the same in every language.
//
// fileStagingBuffer is not ours: 35 other loaders read into the same address, and one of them
// declares it as 0x30000 bytes. Anything left there is only valid until the next load.
//
// The size out-param is written and never read. It has to be volatile or the compiler drops the
// stack slot the original keeps for it, and the frame comes out a word short.
extern "C" ARM void LoadMonsterBattleDataTable(void* p0, void* p1) {
    volatile unsigned int size;
    BackgroundLoader::AddLockGlobal();
    void* buf = LoadFileIntoMemory(&strDataPrmMonBtldataNat, &fileStagingBuffer, (unsigned int*)&size);
    (void)size;
    func_02070a30(p0, p1, buf);
    BackgroundLoader::RemoveLockGlobal();
}
