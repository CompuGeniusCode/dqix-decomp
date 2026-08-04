#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);
struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);
struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);
extern "C" void func_0203066c(struct ResetStruct*, int*);

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

    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c((struct ResetStruct*)local, &data_ov001_02164b80);
    InitBufferReader((struct StreamState*)local, buffer, length);
    RunLoopIfValid02030774((struct Struct02030774*)local);

    self->field4 = data_ov001_02165800.word0;
    data_ov001_02165800.word0 = 0;
    void* mem = alloc->Allocate(self->field4 * 8);
    self->field0 = (int)mem;
    if (mem == NULL) {
        self->field4 = 0;
        return;
    }

    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c((struct ResetStruct*)local, &data_ov001_02164b90);
    InitBufferReader((struct StreamState*)local, buffer, length);
    RunLoopIfValid02030774((struct Struct02030774*)local);
}
