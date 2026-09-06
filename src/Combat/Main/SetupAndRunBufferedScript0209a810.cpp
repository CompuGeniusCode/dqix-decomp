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

extern char data_020f1668[];
extern char data_0211e33c[];
extern char data_020f1640[];

struct Ctx0209a810 { void* field0; };
extern struct Ctx0209a810* data_02109ba8;

// USA: func_0209a810
ARM void SetupAndRunBufferedScript0209a810(struct Ctx0209a810* ctx, void* value) {
    unsigned int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();

    if (LoadFileIntoMemory(data_020f1668, data_0211e33c, &count) != NULL) {
        ctx->field0 = value;
        memset(value, 0, 0x550);
        data_02109ba8 = ctx;
        _ZN6Script10InitializeEv((struct ResetStruct*)buf);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, data_020f1640);
        _ZN6Script4LoadEPKvj((struct StreamState*)buf, (struct StreamHeader*)data_0211e33c, count);
        _ZN6Script7ExecuteEv((struct Struct02030774*)buf);
        data_02109ba8 = NULL;
    }
    BackgroundLoader::RemoveLockGlobal();
}
