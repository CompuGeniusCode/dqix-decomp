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

extern char data_020f15d4[];
extern char data_0211e33c[];
extern char data_020f15c4[];

// USA: func_02099f6c
ARM void PrepareAndRunBufferedScript02099f6c(char* param0) {
    int count;
    char buf[0x430];

    memset(param0, 0, 0x150);
    ShiftInBitOnGlobalObject();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(data_020f15d4, data_0211e33c, (unsigned int*)&count);
    if (header != 0) {
        ResetFieldsReturnTrue((struct ResetStruct*)buf);
        func_0203066c(buf, data_020f15c4);
        InitBufferReader((struct StreamState*)buf, header, count);
        RunLoopIfValid02030774((struct Struct02030774*)buf);
    }
    HalveGlobalObjectCounter();
}
