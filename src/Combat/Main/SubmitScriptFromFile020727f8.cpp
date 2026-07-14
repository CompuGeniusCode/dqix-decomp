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

extern char data_0211e33c[];
extern int data_020f0cc8;

struct Global02108db0_020727f8 {
    unsigned char field0;
    char pad1;
    unsigned short field2;
    void* field4;
    void* field8;
    int fieldc;
    void* field10;
};
extern struct Global02108db0_020727f8 data_02108db0;

// USA: func_020727f8
ARM void SubmitScriptFromFile020727f8(void* param0, const char* path, int param2, void* param3, unsigned char stackArg) {
    unsigned int count;
    char buf[0x430];

    ShiftInBitOnGlobalObject();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(path, data_0211e33c, &count);
    if (header != 0) {
        data_02108db0.field10 = param0;
        data_02108db0.fieldc = 0;
        data_02108db0.field8 = &param2;
        data_02108db0.field2 = 1;
        data_02108db0.field4 = param3;
        data_02108db0.field0 = stackArg;

        ResetFieldsReturnTrue((struct ResetStruct*)buf);
        func_0203066c(buf, &data_020f0cc8);
        InitBufferReader((struct StreamState*)buf, header, count);
        RunLoopIfValid02030774((struct Struct02030774*)buf);
    }
    HalveGlobalObjectCounter();
}
