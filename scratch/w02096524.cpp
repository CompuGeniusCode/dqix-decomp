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

void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void func_0203066c(void* state, void* dataPtr);

extern char data_020f14b0[];
extern char data_0211e33c[];
extern char data_020f1444[];

struct Struct02109404 {
    char pad[0x10];
    void* field10;
};
extern struct Struct02109404 data_02109404;

// USA: func_02096524
ARM void SetupAndRunBufferedScript02096524(void* ctx) {
    unsigned int count;
    char buf[0x430];

    ShiftInBitOnGlobalObject();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(data_020f14b0, data_0211e33c, &count);
    if (header != NULL) {
        *(void**)((char*)&data_02109404 + 0x10) = (char*)ctx + 0xac;
        unsigned int savedCount = count;
        ResetFieldsReturnTrue((struct ResetStruct*)buf);
        func_0203066c(buf, data_020f1444);
        InitBufferReader((struct StreamState*)buf, header, savedCount);
        RunLoopIfValid02030774((struct Struct02030774*)buf);
    }
    HalveGlobalObjectCounter();
}
