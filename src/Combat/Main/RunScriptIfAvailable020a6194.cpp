#include <globaldefs.h>

void ShiftInBitOnGlobalObject(void);
void HalveGlobalObjectCounter(void);

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

int LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" int func_0203066c(void* state, void* buffer);

extern char data_020f1b14;
extern char data_0211e33c;
extern char data_020f1b04;

// USA: func_020a6194
ARM void RunScriptIfAvailable020a6194(void) {
    int count;
    char buf[0x430];
    int header;

    ShiftInBitOnGlobalObject();
    count = 0;
    header = LoadFileIntoMemory(&data_020f1b14, &data_0211e33c, (unsigned int*)&count);
    if (header != 0) {
        ResetFieldsReturnTrue((struct ResetStruct*)buf);
        func_0203066c(buf, &data_020f1b04);
        InitBufferReader((struct StreamState*)buf, (struct StreamHeader*)header, count);
        RunLoopIfValid02030774((struct Struct02030774*)buf);
    }
    HalveGlobalObjectCounter();
}
