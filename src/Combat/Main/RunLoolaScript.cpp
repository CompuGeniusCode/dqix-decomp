#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct ResetStruct {
    int numSupportedOpcodes;
    int opcodeLookup;
    int unsupportedOpcodeProc;
    int pCode;
    int codeLength;
    int pHeader;
    int w18;
    int dataSection;
    int altDataSection;
    int nextInstruction;
    int currentInstructionIndex;
    char currentInstructionParams[0x400];
    unsigned char unknown42c;
};
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* script);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* script, struct StreamHeader* buffer, int length);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* script, void* opcodeTable);

struct Script;
extern "C" int _ZN6Script7ExecuteEv(struct Script* script);

extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);

struct ScriptOpcodeContext { void* allocator; void* outputList; };
extern struct ScriptOpcodeContext data_02109fe0;

extern int strDataMapLoolaGp2;
extern int strLoolaLgBin;
extern int data_020f1b6c;

// Runs loola_<LG>.bin out of data/map/loola.gp2 as one Script, with the background loader locked for
// the duration, presumably so the extracted buffer stays put and nothing is queued underneath it. The
// two arguments go into the globals at 0x02109fe0 that the loola opcode handlers read: func_020a7f5c
// allocates through the word at +0x0 and func_020a7f88 appends into the list at +0x4, so the second
// argument is the allocator and the first the destination list. The stack object is the whole Script
// - the eleven words up to currentInstructionIndex, then 128 Parameter entries and the byte at
// +0x42c - and data_020f1b6c is its opcode table. ov002 calls this twice and ov017 once. Nothing
// here says what loola names.
extern "C" ARM void RunLoolaScript(void* outputList, void* allocator) {
    BackgroundLoader::AddLockGlobal();
    int fileSize = 0;
    void* fileData = ExtractFileFromGP2((const char*)&strDataMapLoolaGp2, (const char*)&strLoolaLgBin, (unsigned int*)&fileSize);
    if (fileData != 0) {
        struct ResetStruct script;
        data_02109fe0.allocator = allocator;
        data_02109fe0.outputList = outputList;
        _ZN6Script10InitializeEv(&script);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&script, &data_020f1b6c);
        _ZN6Script4LoadEPKvj((struct StreamState*)&script, (struct StreamHeader*)fileData, fileSize);
        _ZN6Script7ExecuteEv((struct Script*)&script);
    }
    BackgroundLoader::RemoveLockGlobal();
}
