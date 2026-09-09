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

extern char strDataPrmSkilltableBin[];
extern char fileStagingBuffer[];
extern char data_020f15e8[];

struct Ctx0209a348 { void* field0; };
extern struct Ctx0209a348* data_02109ba4;

// USA: func_0209a348
// The only file path in this function's literal pool is "data/prm/skilltable.bin".
extern "C" ARM void RunSkillTableScript(struct Ctx0209a348* ctx, void* value) {
    unsigned int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(strDataPrmSkilltableBin, fileStagingBuffer, &count);
    if (header != NULL) {
        ctx->field0 = value;
        data_02109ba4 = ctx;
        _ZN6Script10InitializeEv((struct ResetStruct*)buf);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, data_020f15e8);
        _ZN6Script4LoadEPKvj((struct StreamState*)buf, header, count);
        _ZN6Script7ExecuteEv((struct Struct02030774*)buf);
        data_02109ba4 = NULL;
    }
    BackgroundLoader::RemoveLockGlobal();
}
