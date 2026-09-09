#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* obj);
struct SearchObj0202ff34;
extern "C" unsigned int func_ov001_0215a750(const char* path, void** outPtr);
extern "C" void func_ov001_021537b0(void* p0, int p1, int p2, int p3);

extern const char strDataStr_02165745[];

struct Global021658b8 {
    int field0;
    char pad[0x8c - 0x4];
    unsigned char field8c;
};
extern Global021658b8 data_ov001_021658b8;
extern int data_ov001_021658d8;

// Builds the event overlay's id-to-string table from a file the script names, the path being "data/"
// plus the string argument. func_ov001_021537b0 runs the file twice -- once to count entries, once
// to store them -- leaving (id, string) pairs in data_ov001_021658d8. The strings are display text:
// func_ov001_0215e2a4 hands one to the same func_0204500c call it makes with a raw script string,
// and func_ov001_0215e7c0 renders one onto a full-screen 0x20 by 0x18 tile surface. The 0x11-byte
// copy in func_ov001_0215e444 hints at a fixed-width field but does not settle it.
extern "C" ARM int LoadEventStringTable(void* param0) {
    char buf[0x28];
    int out1;
    int out2;
    int flag;

    sprintf(buf, strDataStr_02165745, func_ov017_021d612c(param0));
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
    func_ov001_021537b0(&data_ov001_021658d8, data_ov001_021658b8.field0, out1, out2);
    if (flag != 0) {
        BackgroundLoader::RemoveLockGlobal();
    }
    data_ov001_021658b8.field8c = 0;
    return 1;
}
