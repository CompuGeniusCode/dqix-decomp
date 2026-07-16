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

struct Obj0218e098 {
    char pad[8];
    int field8;
};
extern struct Obj0218e098* data_ov016_0219d1bc;
extern char data_ov016_0219d054[];
extern char data_0211e33c[];
extern char data_ov016_0219d044[];

// USA: func_ov016_0218e098
ARM void RegisterObjectAndRunScript0218e098(struct Obj0218e098* param0, int param1) {
    unsigned int count;
    char local[0x430];

    param0->field8 = param1;
    data_ov016_0219d1bc = param0;
    ShiftInBitOnGlobalObject();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(data_ov016_0219d054, data_0211e33c, &count);
    if (header != 0) {
        ResetFieldsReturnTrue((struct ResetStruct*)local);
        func_0203066c(local, data_ov016_0219d044);
        InitBufferReader((struct StreamState*)local, header, count);
        RunLoopIfValid02030774((struct Struct02030774*)local);
    }
    HalveGlobalObjectCounter();
    param0->field8 = 0;
}
