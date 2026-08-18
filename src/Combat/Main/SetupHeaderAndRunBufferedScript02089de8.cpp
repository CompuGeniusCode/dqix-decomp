#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

int LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" void func_0203066c(void* state, void* dataPtr);

extern char data_0211e33c;
extern char data_020f1088;
extern char data_020f109e;
extern char data_020f1048;

struct Container02108efc {
    void* field0;
    int field4;
    int field8;
    void* fieldc;
};
extern struct Container02108efc data_02108efc;

// USA: func_02089de8
ARM void SetupHeaderAndRunBufferedScript02089de8(void* param0, void* param1, const char* param2) {
    BackgroundLoader::AddLockGlobal();
    unsigned int count;
    char buf[0x430];
    struct StreamHeader* header;
    char* srcBuf = &data_0211e33c;
    unsigned int* pCount = &count;
    if (param2 != 0) {
        header = (struct StreamHeader*)LoadFileIntoMemory(param2, srcBuf, pCount);
    } else {
        header = (struct StreamHeader*)ExtractFileFromGP2(&data_020f1088, &data_020f109e, pCount);
    }
    if (header != 0) {
        data_02108efc.field0 = param0;
        data_02108efc.fieldc = param1;
        data_02108efc.field8 = 0;
        data_02108efc.field4 = 0;
        ResetFieldsReturnTrue((struct ResetStruct*)buf);
        func_0203066c(buf, &data_020f1048);
        InitBufferReader((struct StreamState*)buf, header, count);
        RunLoopIfValid02030774((struct Struct02030774*)buf);
    }
    BackgroundLoader::RemoveLockGlobal();
}
