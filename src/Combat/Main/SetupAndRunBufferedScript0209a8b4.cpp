#include <globaldefs.h>

#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Ctx0209a8b4 {
    void* field0;
};
extern struct Ctx0209a8b4* data_02109ba8;
extern char data_020f1640[];

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, char*);

// USA: func_0209a8b4
ARM void SetupAndRunBufferedScript0209a8b4(struct Ctx0209a8b4* ctx, SafeAllocator* alloc, struct StreamHeader* buffer, int length) {
    void* mem = alloc->Allocate(0x550);
    ctx->field0 = mem;
    if (mem != NULL) {
        memset(mem, 0, 0x550);
        char local[0x430];
        data_02109ba8 = ctx;
        ResetFieldsReturnTrue((struct ResetStruct*)local);
        func_0203066c((struct ResetStruct*)local, data_020f1640);
        InitBufferReader((struct StreamState*)local, buffer, length);
        RunLoopIfValid02030774((struct Struct02030774*)local);
        data_02109ba8 = NULL;
    }
}
