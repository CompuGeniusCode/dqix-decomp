#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* command);
struct BackgroundLoaderInstance;
extern "C" unsigned int func_ov001_0215a750(const char* path, void** outPtr);
extern "C" void func_ov001_021537b0(void* table, int allocator, int scriptData, int scriptLength);

extern const char strDataStr_02165745[];

struct EventOverlayState {
    int allocator;
    char unknown4[0x8c - 0x4];
    unsigned char unknown8c;
};
extern EventOverlayState data_ov001_021658b8;
extern int data_ov001_021658d8;

// Builds the event overlay's id-to-string table from a file the script names, the path being "data/"
// plus the string argument. func_ov001_021537b0 runs the file twice -- once to count entries, once
// to store them -- leaving (id, string) pairs in data_ov001_021658d8, whose two words are the entry
// array and its count, and it runs them as compiled Script binaries against two different opcode
// tables. The allocator it uses is the first of the eight SafeAllocator slots at
// data_ov001_021658b8. The strings are display text: func_ov001_0215e2a4 hands one to the same
// func_0204500c call it makes with a raw script string, and func_ov001_0215e7c0 renders one onto a
// full-screen 0x20 by 0x18 tile surface. The 0x11-byte copy in func_ov001_0215e444 hints at a
// fixed-width field but does not settle it. The byte at +0x8c is only ever cleared -- here and in
// func_ov001_0215acf8, func_ov001_0215e1cc, func_ov001_0215e27c and func_ov001_0215e444 -- and
// never read, so what it marks is not established.
extern "C" ARM int LoadEventStringTable(void* command) {
    char buf[0x28];
    int scriptData;
    int scriptLength;
    int tookLock;

    sprintf(buf, strDataStr_02165745, func_ov017_021d612c(command));
    tookLock = 0;
    ((BackgroundLoader*)((BackgroundLoaderInstance*)(int)BackgroundLoader::GetInstance()))->GetLoadedFileByName((const char*)(buf), (void**)(&scriptData), (unsigned int*)(&scriptLength));
    if (scriptData == 0) {
        BackgroundLoader::AddLockGlobal();
        tookLock = 1;
        if (func_ov001_0215a750(buf, (void**)&scriptData) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }
    func_ov001_021537b0(&data_ov001_021658d8, data_ov001_021658b8.allocator, scriptData, scriptLength);
    if (tookLock != 0) {
        BackgroundLoader::RemoveLockGlobal();
    }
    data_ov001_021658b8.unknown8c = 0;
    return 1;
}
