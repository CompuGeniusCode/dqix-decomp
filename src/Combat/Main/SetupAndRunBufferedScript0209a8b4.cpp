#include <globaldefs.h>

#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Ctx0209a8b4 {
    void* field0;
};
extern struct Ctx0209a8b4* data_02109ba8;
extern char data_020f1640[];

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, char*);

// USA: func_0209a8b4
ARM void SetupAndRunBufferedScript0209a8b4(struct Ctx0209a8b4* ctx, SafeAllocator* alloc, struct StreamHeader* buffer, int length) {
    void* mem = alloc->Allocate(0x550);
    ctx->field0 = mem;
    if (mem != NULL) {
        memset(mem, 0, 0x550);
        char local[0x430];
        data_02109ba8 = ctx;
        _ZN6Script10InitializeEv((struct ResetStruct*)local);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, data_020f1640);
        _ZN6Script4LoadEPKvj((struct StreamState*)local, buffer, length);
        _ZN6Script7ExecuteEv((struct Struct02030774*)local);
        data_02109ba8 = NULL;
    }
}
