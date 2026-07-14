#include <globaldefs.h>

#include "std_library_functions.h"

void ShiftInBitOnGlobalObject(void);
void HalveGlobalObjectCounter(void);

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void func_0203066c(void* state, void* dataPtr);

extern char data_020f1668[];
extern char data_0211e33c[];
extern char data_020f1640[];

struct Ctx0209a810 { void* field0; };
extern struct Ctx0209a810* data_02109ba8;

// USA: func_0209a810
ARM void SetupAndRunBufferedScript0209a810(struct Ctx0209a810* ctx, void* value) {
    unsigned int count;
    char buf[0x430];

    ShiftInBitOnGlobalObject();

    if (LoadFileIntoMemory(data_020f1668, data_0211e33c, &count) != NULL) {
        ctx->field0 = value;
        memset(value, 0, 0x550);
        data_02109ba8 = ctx;
        ResetFieldsReturnTrue((struct ResetStruct*)buf);
        func_0203066c(buf, data_020f1640);
        InitBufferReader((struct StreamState*)buf, (struct StreamHeader*)data_0211e33c, count);
        RunLoopIfValid02030774((struct Struct02030774*)buf);
        data_02109ba8 = NULL;
    }
    HalveGlobalObjectCounter();
}
