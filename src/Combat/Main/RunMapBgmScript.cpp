#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

int LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" int _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* buffer);

extern char strDataBinMapbgmBin;
extern char fileStagingBuffer;
extern char data_020f1718;

// USA: func_0209cbcc
// The only file path in this function's literal pool is "data/bin/mapbgm.bin".
extern "C" ARM void RunMapBgmScript(void) {
    int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();
    if (LoadFileIntoMemory(&strDataBinMapbgmBin, &fileStagingBuffer, (unsigned int*)&count) != 0) {
        _ZN6Script10InitializeEv((struct ResetStruct*)buf);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, &data_020f1718);
        _ZN6Script4LoadEPKvj((struct StreamState*)buf, (struct StreamHeader*)&fileStagingBuffer, count);
        _ZN6Script7ExecuteEv((struct Struct02030774*)buf);
    }
    BackgroundLoader::RemoveLockGlobal();
}
