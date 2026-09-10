#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Filesystem/FileIO.h"

extern "C" void* func_0208247c(void* obj);
extern "C" void func_02082490(void* obj, void* addr, unsigned int size, unsigned short val, int extra);
extern "C" void func_02083cbc(void* a, void* obj, void* tail);
extern "C" void func_02083e28(void* a, int unknownArg);

extern char strDataPrmLevelNumBin_020f1019[];
extern unsigned char fileStagingBuffer[0x30000];
struct LevelStatBlock { unsigned int w[5]; };
struct LevelStatTail { unsigned char bytes[0x18]; };
struct LevelStats {
    LevelStatBlock block0;
    LevelStatBlock block1;
    LevelStatBlock block2;
    LevelStatTail tail;
};

// Loads the level table for the vocation a character record is currently in and applies it to that
// record. The vocation index is the word at +0x950 and goes straight into "data/prm/level%d.bin",
// of which the ROM holds level0 through level12, so there are thirteen vocations; the record's
// per-vocation levels start at +0x16c and the halfword for the current vocation is the row
// func_02082490 pulls out of the loaded file. GetCombatantLevel reads the same two fields and
// agrees on both. The 0x54-byte result -- three five-word blocks and a 0x18-byte tail, the size
// func_0208247c clears -- is applied to the record by func_02083cbc, and copied out to the caller's
// buffer as well when one is given. func_02083e28 is called on the record straight after but is
// handed no part of the block, so what it does with the result is not established either. What the
// individual blocks hold is not established; neither func_02082490 nor func_02083cbc is decompiled.
extern "C" ARM void LoadLevelTableForVocation(void* a, void* outStats) {
    char path[0x18];
    sprintf(path, strDataPrmLevelNumBin_020f1019, *(int*)((char*)a + 0x950));
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* addr = LoadFileIntoMemory(path, &fileStagingBuffer, &size);
    if (addr != NULL) {
        LevelStats local;
        func_0208247c(&local);
        unsigned short val = *(unsigned short*)((char*)a + *(int*)((char*)a + 0x950) * 2 + 0x16c);
        func_02082490(&local, addr, size, val, 0);
        func_02083cbc(a, &local, &local.tail);
        func_02083e28(a, 0);
        if (outStats != NULL) {
            LevelStats* outBlock = (LevelStats*)outStats;
            outBlock->block0 = local.block0;
            outBlock->block1 = local.block1;
            outBlock->block2 = local.block2;
            outBlock->tail = local.tail;
        }
    }
    BackgroundLoader::RemoveLockGlobal();
}
