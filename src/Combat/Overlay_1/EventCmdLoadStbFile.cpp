#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* obj);
struct SearchObj0202ff34;
extern "C" unsigned int func_ov001_0215a750(const char* path, void** outPtr);
extern "C" void func_ov001_021538c8(void);
extern "C" void func_ov001_021538d4(int p0, void* unused1, SafeAllocator* alloc);

extern const char strDataStr_02165745[];
extern SafeAllocator* data_ov001_021658b8[8];

// Handler for event script command 0x200, reached only through the entry at 0x021651b0 in ov001's
// opcode table. It loads data/<name> from the operand at +4 of the command record, copies it out of
// the shared staging buffer into its own allocation, and initialises the reader data_ov001_02165828
// over it with func_ov017_021d4c04. That init checks the header for "SB2" -- the .stb magic -- and
// otherwise returns without marking the object ready, while this still returns 1, so a wrong file
// fails silently. The operand carries subdirectory and extension, e.g. "menu/auction.stb".
extern "C" ARM int EventCmdLoadStbFile(void* param0) {
    char buf[0x20];
    int out1;
    int out2;
    SafeAllocator* allocator;
    int flag;

    void* name = func_ov017_021d612c(param0);
    if (GetBattleStruct() == NULL) {
        return 0;
    }
    sprintf(buf, strDataStr_02165745, name);
    allocator = data_ov001_021658b8[0];
    flag = 0;
    ((BackgroundLoader*)((SearchObj0202ff34*)(int)BackgroundLoader::GetInstance()))->GetLoadedFileByName((const char*)(buf), (void**)(&out1), (unsigned int*)(&out2));
    if (out1 == 0) {
        BackgroundLoader::AddLockGlobal();
        flag = 1;
        if (func_ov001_0215a750(buf, (void**)&out1) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }
    void* newObj = allocator->Allocate(out2);
    if (newObj == NULL) {
        if (flag != 0) {
            BackgroundLoader::RemoveLockGlobal();
        }
        return 0;
    }
    memcpy(newObj, (void*)out1, out2);
    if (flag != 0) {
        BackgroundLoader::RemoveLockGlobal();
    }
    func_ov001_021538c8();
    func_ov001_021538d4((int)newObj, NULL, allocator);
    return 1;
}
