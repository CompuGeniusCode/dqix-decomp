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
extern "C" void func_0203066c(void* state, void* dataPtr);

extern char data_0211e33c;
extern char data_020ef418;

struct Container0201f040 {
    int f0;
    void* field4;
    void* field8;
};
extern struct Container0201f040 data_020fdc40;

// USA: func_0201f040
ARM void RegisterAndRunBufferedScript0201f040(void* p0, void* p1, struct StreamHeader* headerIn, unsigned int countIn) {
    unsigned int count = countIn;
    int flag = 0;
    struct StreamHeader* header = headerIn;
    char buf[0x430];

    if (header == NULL) {
        int usedFlag;
        ShiftInBitOnGlobalObject();
        usedFlag = flag;
        flag = 1;
        header = (struct StreamHeader*)LoadFileIntoMemory((const char*)usedFlag, &data_0211e33c, &count);
    }
    if (header != NULL) {
        data_020fdc40.field4 = p1;
        data_020fdc40.field8 = p0;
        ResetFieldsReturnTrue((struct ResetStruct*)buf);
        func_0203066c(buf, &data_020ef418);
        InitBufferReader((struct StreamState*)buf, header, count);
        RunLoopIfValid02030774((struct Struct02030774*)buf);
        data_020fdc40.field8 = 0;
        data_020fdc40.field4 = 0;
    }
    if (flag) {
        HalveGlobalObjectCounter();
    }
}
