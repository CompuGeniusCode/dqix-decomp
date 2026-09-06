#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);
struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);
struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

struct Global021537b0 { int word0; SafeAllocator* allocPtr; void* selfPtr; };
extern Global021537b0 data_ov001_02165800;
extern int data_ov001_02164b80;
extern int data_ov001_02164b90;

struct Self021537b0 { int field0; int field4; };

// USA: func_ov001_021537b0
extern "C" ARM void func_ov001_021537b0(Self021537b0* self, SafeAllocator* alloc, struct StreamHeader* buffer, int length) {
    char local[0x430];
    self->field0 = 0;
    self->field4 = 0;
    data_ov001_02165800.word0 = 0;
    data_ov001_02165800.allocPtr = alloc;
    data_ov001_02165800.selfPtr = self;

    _ZN6Script10InitializeEv((struct ResetStruct*)local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_ov001_02164b80);
    _ZN6Script4LoadEPKvj((struct StreamState*)local, buffer, length);
    _ZN6Script7ExecuteEv((struct Struct02030774*)local);

    self->field4 = data_ov001_02165800.word0;
    data_ov001_02165800.word0 = 0;
    void* mem = alloc->Allocate(self->field4 * 8);
    self->field0 = (int)mem;
    if (mem == NULL) {
        self->field4 = 0;
        return;
    }

    _ZN6Script10InitializeEv((struct ResetStruct*)local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_ov001_02164b90);
    _ZN6Script4LoadEPKvj((struct StreamState*)local, buffer, length);
    _ZN6Script7ExecuteEv((struct Struct02030774*)local);
}
