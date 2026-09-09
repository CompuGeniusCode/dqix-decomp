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

struct Obj0218e098 {
    char pad[8];
    int field8;
};
extern struct Obj0218e098* data_ov016_0219d1bc;
extern char strDataMovieMovielistBin[];
extern char fileStagingBuffer[];
extern char data_ov016_0219d044[];

// Loads data/movie/movielist.bin and runs it as a script against the movie viewer's own opcode
// table at data_ov016_0219d044. The viewer publishes itself in the global at 0x0219d1bc and parks
// its argument at +8 for the length of the run so those opcodes can reach both, then zeroes +8 on
// the way out. A global background-loader lock is held across the whole thing. data/movie holds
// this list alongside the six .mods movie files it presumably indexes.
extern "C" ARM void RunMovieListScript(struct Obj0218e098* param0, int param1) {
    unsigned int count;
    char local[0x430];

    param0->field8 = param1;
    data_ov016_0219d1bc = param0;
    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(strDataMovieMovielistBin, fileStagingBuffer, &count);
    if (header != 0) {
        _ZN6Script10InitializeEv((struct ResetStruct*)local);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(local, data_ov016_0219d044);
        _ZN6Script4LoadEPKvj((struct StreamState*)local, header, count);
        _ZN6Script7ExecuteEv((struct Struct02030774*)local);
    }
    BackgroundLoader::RemoveLockGlobal();
    param0->field8 = 0;
}
