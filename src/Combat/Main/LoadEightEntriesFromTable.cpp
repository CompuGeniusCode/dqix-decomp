#include <globaldefs.h>

extern "C" void func_02003ce8(void* buf, void* table, int index);
extern "C" void func_0204719c(void* obj);
extern "C" void func_02047b40(void* elem, int offset, void* param2);

extern int OpenPathAndGetImageOffset(void* path);

extern int data_020ef7c4;

struct PathBuf0202f310 { char path[0x28]; };

// USA: func_0202f310
ARM void LoadEightEntriesFromTable(char* obj, void* param2) {
    struct PathBuf0202f310 buf;
    char* p;
    int i;
    p = obj;
    for (i = 0; i < 8; i++) {
        int offset;
        func_02003ce8(&buf, &data_020ef7c4, i);
        offset = OpenPathAndGetImageOffset(&buf);
        func_0204719c(p);
        func_02047b40(p, offset, param2);
        p += 0x88;
    }
}
