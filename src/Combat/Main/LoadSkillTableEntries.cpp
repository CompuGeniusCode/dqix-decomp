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
extern char data_020f1608[];

struct Ctx0209a3dc { void* field0; };
extern struct Ctx0209a3dc* data_02109ba4;

// Runs data/prm/skilltable.bin as a script so the opcode handlers at data_020f1608 can fill the
// caller's table; func_0201133c clears 0x570 bytes of game state and hands them in as the destination.
// ctx is parked in data_02109ba4 for the duration because that is how the handlers reach it, and the
// background loader is locked because the file lands in the shared staging buffer. Those 0x570 bytes
// are 116 twelve-byte records that func_0209a594 searches by 11-bit id. RunSkillTableScript at
// 0x0209a348 runs the same file with a different opcode table into a stack-local ctx, a transient pass.
extern "C" ARM void LoadSkillTableEntries(struct Ctx0209a3dc* ctx, void* value) {
    unsigned int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(strDataPrmSkilltableBin, fileStagingBuffer, &count);
    if (header != NULL) {
        ctx->field0 = value;
        data_02109ba4 = ctx;
        _ZN6Script10InitializeEv((struct ResetStruct*)buf);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, data_020f1608);
        _ZN6Script4LoadEPKvj((struct StreamState*)buf, header, count);
        _ZN6Script7ExecuteEv((struct Struct02030774*)buf);
        data_02109ba4 = NULL;
    }
    BackgroundLoader::RemoveLockGlobal();
}
