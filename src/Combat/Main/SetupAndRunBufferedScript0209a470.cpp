#include <globaldefs.h>

#include "Memory/SafeAllocator.h"

struct Ctx0209a470 {
    void* field0;
};
extern struct Ctx0209a470* data_02109ba4;
extern char data_020f15e8[];

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, char*);

// USA: func_0209a470
ARM void SetupAndRunBufferedScript0209a470(struct Ctx0209a470* ctx, SafeAllocator* alloc, struct StreamHeader* buffer, int length) {
    void* mem = alloc->Allocate(0xd74);
    ctx->field0 = mem;
    if (mem != NULL) {
        char local[0x430];
        data_02109ba4 = ctx;
        _ZN6Script10InitializeEv((struct ResetStruct*)local);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, data_020f15e8);
        _ZN6Script4LoadEPKvj((struct StreamState*)local, buffer, length);
        _ZN6Script7ExecuteEv((struct Struct02030774*)local);
        data_02109ba4 = NULL;
    }
}
