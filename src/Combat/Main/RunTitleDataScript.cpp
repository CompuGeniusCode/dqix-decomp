#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct ScriptState {
    int unknown0;
    int unknown4;
    int unknown8;
    int unknownC;
    int unknown10;
    int unknown14;
    int unknown18;
    int unknown1C;
    int unknown20;
    int unknown24;
    int unknown28;
    char unknown2c[0x400];
    unsigned char unknown42c;
};
extern "C" int _ZN6Script10InitializeEv(struct ScriptState* script);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* script, struct StreamHeader* buffer, int length);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* p, void* q);

struct ScriptState;
extern "C" int _ZN6Script7ExecuteEv(struct ScriptState* p);

extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);

struct ScriptOpcodeContext {
    unsigned char paramMask;
    char unknown1;
    unsigned short countOverride;
    void* target;
    void* allocator;
    int countOverrideEnabled;
};
extern struct ScriptOpcodeContext data_02109d94;

extern int strDataBinTtldataGp2;
extern int strTtldataLgBin;
extern int data_020f18ec;

// USA: func_020a13e4
// Runs the title screen data script. It parks its five arguments in the global at data_02109d94
// -- the array object at +0x4, the allocator at +0x8, the override gate at +0xc, the count override
// at +0x2 and the parameter mask at +0x0 -- then pulls ttldata_<LG>.bin out of data/bin/ttldata.gp2
// and runs it on one Script built on the stack, with the opcode table at data_020f18ec. The two
// array opcodes that are decompiled, func_020a10cc and func_020a14fc, are the only readers of that
// global: the mask picks which of the four script parameters are summed into the element count,
// +0xc and +0x2 replace that sum outright, and +0x8 is the SafeAllocator the array and its bitmap
// come from. func_020a147c is the same runner over a buffer the caller already holds. The
// BackgroundLoader lock is held across both the extract and the run, and the return is thrown away.
extern "C" ARM void RunTitleDataScript(void* param0, void* param1, int param2, unsigned short param3, unsigned char param4) {
    if (param1 != 0) {
        int localVar;
        void* result;
        data_02109d94.target = param0;
        data_02109d94.allocator = param1;
        data_02109d94.countOverrideEnabled = param2;
        data_02109d94.countOverride = param3;
        data_02109d94.paramMask = param4;
        BackgroundLoader::AddLockGlobal();
        localVar = 0;
        result = ExtractFileFromGP2((const char*)&strDataBinTtldataGp2, (const char*)&strTtldataLgBin, (unsigned int*)&localVar);
        if (result != 0) {
            struct ScriptState local;
            _ZN6Script10InitializeEv(&local);
            _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&local, &data_020f18ec);
            _ZN6Script4LoadEPKvj((struct StreamState*)&local, (struct StreamHeader*)result, localVar);
            _ZN6Script7ExecuteEv((struct ScriptState*)&local);
        }
        BackgroundLoader::RemoveLockGlobal();
    }
}
