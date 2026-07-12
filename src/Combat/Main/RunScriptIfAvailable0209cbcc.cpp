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

extern "C" int func_02075098(void* a, void* b, int* outCount);
extern "C" int func_0203066c(void* state, void* buffer);

extern char data_020f1744;
extern char data_0211e33c;
extern char data_020f1718;

// USA: func_0209cbcc
ARM void RunScriptIfAvailable0209cbcc(void) {
    int count;
    char buf[0x430];

    ShiftInBitOnGlobalObject();
    if (func_02075098(&data_020f1744, &data_0211e33c, &count) != 0) {
        ResetFieldsReturnTrue((struct ResetStruct*)buf);
        func_0203066c(buf, &data_020f1718);
        InitBufferReader((struct StreamState*)buf, (struct StreamHeader*)&data_0211e33c, count);
        RunLoopIfValid02030774((struct Struct02030774*)buf);
    }
    HalveGlobalObjectCounter();
}
