#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* script);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* script, struct StreamHeader* buffer, int length);

struct ScriptExecState;
extern "C" int _ZN6Script7ExecuteEv(struct ScriptExecState* script);

int LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* dataPtr);

extern char fileStagingBuffer;
extern char strDataBinPresetdtGp2;
extern char strPresetdtLgBin;
extern char data_020f1048;

struct PresetScriptContext {
    void* target;
    int unknown4;
    int unknown8;
    void* allocator;
};
extern struct PresetScriptContext data_02108efc;

// USA: func_02089de8
// The file paths in this function's literal pool are "data/bin/presetdt.gp2" and
// "presetdt_<LG>.bin"; the third argument, when it is not null, names a file to run in place of
// that archive member. The four-word global it fills in is the context the presetdt opcodes read
// back: func_020899fc and func_02089ac0 take the object at +0 as the array they populate and the
// SafeAllocator at +0xc as what they allocate its strings from, which is what makes the first two
// arguments the target and the allocator. What the words at +4 and +8, both zeroed here, are for is
// not established. All three Script calls run on the same 0x430 stack buffer, so ResetStruct,
// StreamState and ScriptExecState are three views of one object.
extern "C" ARM void RunPresetDataScript(void* target, void* allocator, const char* overridePath) {
    BackgroundLoader::AddLockGlobal();
    unsigned int count;
    char buf[0x430];
    struct StreamHeader* header;
    char* srcBuf = &fileStagingBuffer;
    unsigned int* pCount = &count;
    if (overridePath != 0) {
        header = (struct StreamHeader*)LoadFileIntoMemory(overridePath, srcBuf, pCount);
    } else {
        header = (struct StreamHeader*)ExtractFileFromGP2(&strDataBinPresetdtGp2, &strPresetdtLgBin, pCount);
    }
    if (header != 0) {
        data_02108efc.target = target;
        data_02108efc.allocator = allocator;
        data_02108efc.unknown8 = 0;
        data_02108efc.unknown4 = 0;
        _ZN6Script10InitializeEv((struct ResetStruct*)buf);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, &data_020f1048);
        _ZN6Script4LoadEPKvj((struct StreamState*)buf, header, count);
        _ZN6Script7ExecuteEv((struct ScriptExecState*)buf);
    }
    BackgroundLoader::RemoveLockGlobal();
}
