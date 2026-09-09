#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct ResetStruct {
    int w0;
    int w4;
    int w8;
    int wc;
    int w10;
    int w14;
    int w18;
    int w1c;
    int w20;
    int w24;
    int w28;
    char pad[0x400];
    unsigned char b42c;
};
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamHeader;
struct StreamState;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* p, void* q);
extern "C" void func_ov015_0218b828();
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char* path, void* buf, unsigned int* outLen);

extern int fileStagingBuffer;
extern int strDataBinCharaview4Bin;
extern void* data_ov015_02194560;
extern int data_ov015_02193fa0;

// Runs the charaview screen's script to completion: data/bin/charaview4.bin unless the caller
// names another file. The script is read into the shared staging buffer and executed inline, so
// the global loader lock is held for the whole run rather than across a queued load. "self" is
// parked in data_ov015_02194560, presumably because the opcode handlers in data_ov015_02193fa0
// have no other way to reach it.
extern "C" ARM void RunCharaviewScript(void* self, const char* path) {
    func_ov015_0218b828();
    BackgroundLoader::AddLockGlobal();

    unsigned int length;
    void* buffer;
    if (path != 0) {
        buffer = _Z18LoadFileIntoMemoryPKcPvPj(path, &fileStagingBuffer, &length);
    } else {
        buffer = _Z18LoadFileIntoMemoryPKcPvPj((const char*)&strDataBinCharaview4Bin, &fileStagingBuffer, &length);
    }

    if (buffer != 0) {
        data_ov015_02194560 = self;

        struct ResetStruct local;
        _ZN6Script10InitializeEv(&local);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&local, &data_ov015_02193fa0);
        _ZN6Script4LoadEPKvj((struct StreamState*)&local, (struct StreamHeader*)buffer, length);
        _ZN6Script7ExecuteEv((struct Struct02030774*)&local);
    }

    BackgroundLoader::RemoveLockGlobal();
}
