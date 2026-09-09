#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

#include "std_library_functions.h"

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* dataPtr);

extern char strDataPrmSpelltableBin_020f1668[];
extern char fileStagingBuffer[];
extern char data_020f1640[];

struct Ctx0209a810 { void* field0; };
extern struct Ctx0209a810* data_02109ba8;

// USA: func_0209a810
// The only file path in this function's literal pool is "data/prm/spelltable.bin".
extern "C" ARM void RunSpellTableScript(struct Ctx0209a810* ctx, void* value) {
    unsigned int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();

    if (LoadFileIntoMemory(strDataPrmSpelltableBin_020f1668, fileStagingBuffer, &count) != NULL) {
        ctx->field0 = value;
        memset(value, 0, 0x550);
        data_02109ba8 = ctx;
        _ZN6Script10InitializeEv((struct ResetStruct*)buf);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, data_020f1640);
        _ZN6Script4LoadEPKvj((struct StreamState*)buf, (struct StreamHeader*)fileStagingBuffer, count);
        _ZN6Script7ExecuteEv((struct Struct02030774*)buf);
        data_02109ba8 = NULL;
    }
    BackgroundLoader::RemoveLockGlobal();
}
