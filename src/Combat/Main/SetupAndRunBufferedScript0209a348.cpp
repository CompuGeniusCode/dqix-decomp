#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void func_0203066c(void* state, void* dataPtr);

extern char data_020f1628[];
extern char data_0211e33c[];
extern char data_020f15e8[];

struct Ctx0209a348 { void* field0; };
extern struct Ctx0209a348* data_02109ba4;

// USA: func_0209a348
ARM void SetupAndRunBufferedScript0209a348(struct Ctx0209a348* ctx, void* value) {
    unsigned int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(data_020f1628, data_0211e33c, &count);
    if (header != NULL) {
        ctx->field0 = value;
        data_02109ba4 = ctx;
        ResetFieldsReturnTrue((struct ResetStruct*)buf);
        func_0203066c(buf, data_020f15e8);
        InitBufferReader((struct StreamState*)buf, header, count);
        RunLoopIfValid02030774((struct Struct02030774*)buf);
        data_02109ba4 = NULL;
    }
    BackgroundLoader::RemoveLockGlobal();
}
