#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* dataPtr);

struct Obj020995c0;
extern struct Obj020995c0* data_02109924;

extern char strDataMapMaplist9Bin_020f155c[];
extern char fileStagingBuffer[];
extern char data_020f1524[];

// USA: func_020998c4
// The only file path in this function's literal pool is "data/map/maplist9.bin".
extern "C" ARM void RunMapListScript(struct Obj020995c0* param0) {
    int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(strDataMapMaplist9Bin_020f155c, fileStagingBuffer, (unsigned int*)&count);
    if (header != 0) {
        data_02109924 = param0;
        _ZN6Script10InitializeEv((struct ResetStruct*)buf);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, data_020f1524);
        _ZN6Script4LoadEPKvj((struct StreamState*)buf, header, count);
        _ZN6Script7ExecuteEv((struct Struct02030774*)buf);
        data_02109924 = 0;
    }
    BackgroundLoader::RemoveLockGlobal();
}
