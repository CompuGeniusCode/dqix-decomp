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
extern "C" int func_0203066c(void* state, void* buffer);

extern char data_020f1744;
extern char data_0211e33c;
extern char data_020f1718;

// USA: func_0209cbcc
ARM void RunScriptIfAvailable0209cbcc(void) {
    int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();
    if (LoadFileIntoMemory(&data_020f1744, &data_0211e33c, (unsigned int*)&count) != 0) {
        ResetFieldsReturnTrue((struct ResetStruct*)buf);
        func_0203066c(buf, &data_020f1718);
        InitBufferReader((struct StreamState*)buf, (struct StreamHeader*)&data_0211e33c, count);
        RunLoopIfValid02030774((struct Struct02030774*)buf);
    }
    BackgroundLoader::RemoveLockGlobal();
}
