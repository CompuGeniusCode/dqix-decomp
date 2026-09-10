#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "System/Memory.h"

extern "C" void* AllocateRoundedToWord(AllocatorUnion* alloc, unsigned int size);
extern "C" char* func_020467c0(void* a, char* b, void** outField44);
extern "C" int func_020b01a4(void* file, void** out);
struct Hdr02b0288;
extern "C" int func_020b01f0(struct Hdr02b0288* h, void** out);
extern "C" void FatalHalt(void);

extern AllocatorUnion data_02114e20;
extern unsigned char fileStagingBuffer[0x30000];
extern const char strDataAniObjLoadingPac;
extern const char strObjLoadingNcgr;
extern const char strObjLoadingNclr;

struct NcgrCharBlock {
    char unknown0[0x10];
    unsigned int size;
    void* data;
};

struct NclrPaletteChunk {
    char unknown0[0xc];
    void* data;
};

struct ObjLoadingGraphics {
    SafeAllocator allocator;
    char unknown14[0x40 - sizeof(SafeAllocator)];
    void* charBuf;
    unsigned int charBufSize;
    void* plttBuf;
    unsigned int plttBufSize;
};

// Pulls the "now loading" object's graphics out of data/ani/obj_loading.pac, which is 768
// bytes and holds exactly obj_loading.NCGR and obj_loading.NCLR. The file itself is read into
// the shared fileStagingBuffer; the 0x300 arena this function creates holds only the two copies
// taken out of it - the character data at its own size, the palette at a fixed 0x20, so sixteen
// colours.
// Called once, from main at 0x02000d9c. The staging read runs under BackgroundLoader's global
// lock, so nothing else may be using that buffer meanwhile.
extern "C" ARM void LoadObjLoadingGraphics(ObjLoadingGraphics* loadingGraphics) {
    unsigned int fileLength;
    void* ncgrNextOut;
    void* nclrNextOut;
    char* ncgrEntry;
    Hdr02b0288* nclrEntry;
    NcgrCharBlock* charBlock;
    NclrPaletteChunk* plttChunk;
    void* stagingBuffer;

    loadingGraphics->allocator.CreateTypeA(AllocateRoundedToWord(&data_02114e20, 0x300), 0x300);
    loadingGraphics->allocator.Reset();
    BackgroundLoader::AddLockGlobal();

    stagingBuffer = fileStagingBuffer;

    fileLength = 0;
    LoadFileIntoMemory(&strDataAniObjLoadingPac, stagingBuffer, &fileLength);

    ncgrNextOut = NULL;
    nclrNextOut = NULL;
    ncgrEntry = func_020467c0(stagingBuffer, (char*)&strObjLoadingNcgr, &ncgrNextOut);
    nclrEntry = (Hdr02b0288*)func_020467c0(stagingBuffer, (char*)&strObjLoadingNclr, &nclrNextOut);

    charBlock = NULL;
    if (!func_020b01a4(ncgrEntry, (void**)&charBlock)) {
        FatalHalt();
    }

    loadingGraphics->charBufSize = charBlock->size;
    loadingGraphics->charBuf = loadingGraphics->allocator.Allocate(loadingGraphics->charBufSize);
    VectorizedInvertedMemcpy(charBlock->data, loadingGraphics->charBuf, loadingGraphics->charBufSize);

    plttChunk = NULL;
    if (!func_020b01f0(nclrEntry, (void**)&plttChunk)) {
        FatalHalt();
    }

    loadingGraphics->plttBufSize = 0x20;
    loadingGraphics->plttBuf = loadingGraphics->allocator.Allocate(loadingGraphics->plttBufSize);
    VectorizedInvertedMemcpy(plttChunk->data, loadingGraphics->plttBuf, loadingGraphics->plttBufSize);

    BackgroundLoader::RemoveLockGlobal();
}
