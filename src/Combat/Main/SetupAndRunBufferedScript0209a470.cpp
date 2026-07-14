#include <globaldefs.h>

#include "Memory/SafeAllocator.h"

struct Ctx0209a470 {
    void* field0;
};
extern struct Ctx0209a470* data_02109ba4;
extern char data_020f15e8[];

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, char*);

// USA: func_0209a470
ARM void SetupAndRunBufferedScript0209a470(struct Ctx0209a470* ctx, SafeAllocator* alloc, struct StreamHeader* buffer, int length) {
    void* mem = alloc->Allocate(0xd74);
    ctx->field0 = mem;
    if (mem != NULL) {
        char local[0x430];
        data_02109ba4 = ctx;
        ResetFieldsReturnTrue((struct ResetStruct*)local);
        func_0203066c((struct ResetStruct*)local, data_020f15e8);
        InitBufferReader((struct StreamState*)local, buffer, length);
        RunLoopIfValid02030774((struct Struct02030774*)local);
        data_02109ba4 = NULL;
    }
}
