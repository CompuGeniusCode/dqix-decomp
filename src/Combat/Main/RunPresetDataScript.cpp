#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

int LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* dataPtr);

extern char fileStagingBuffer;
extern char strDataBinPresetdtGp2;
extern char strPresetdtLgBin;
extern char data_020f1048;

struct Container02108efc {
    void* field0;
    int field4;
    int field8;
    void* fieldc;
};
extern struct Container02108efc data_02108efc;

// USA: func_02089de8
// The file paths in this function's literal pool are "data/bin/presetdt.gp2" and
// "presetdt_<LG>.bin".
extern "C" ARM void RunPresetDataScript(void* param0, void* param1, const char* param2) {
    BackgroundLoader::AddLockGlobal();
    unsigned int count;
    char buf[0x430];
    struct StreamHeader* header;
    char* srcBuf = &fileStagingBuffer;
    unsigned int* pCount = &count;
    if (param2 != 0) {
        header = (struct StreamHeader*)LoadFileIntoMemory(param2, srcBuf, pCount);
    } else {
        header = (struct StreamHeader*)ExtractFileFromGP2(&strDataBinPresetdtGp2, &strPresetdtLgBin, pCount);
    }
    if (header != 0) {
        data_02108efc.field0 = param0;
        data_02108efc.fieldc = param1;
        data_02108efc.field8 = 0;
        data_02108efc.field4 = 0;
        _ZN6Script10InitializeEv((struct ResetStruct*)buf);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, &data_020f1048);
        _ZN6Script4LoadEPKvj((struct StreamState*)buf, header, count);
        _ZN6Script7ExecuteEv((struct Struct02030774*)buf);
    }
    BackgroundLoader::RemoveLockGlobal();
}
