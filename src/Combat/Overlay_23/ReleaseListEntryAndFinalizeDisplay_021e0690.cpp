#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct List0202fec8;
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310*, int);
extern "C" char* func_020e046c(char* buf, void* b, void* c, int idx);
void ClearStruct16(void* p);
struct Struct020dfc40;
void ResetAndDetach020dfc6c(struct Struct020dfc40* p);

extern "C" {
    void func_ov023_021ddf5c(void* obj);
    void func_ov023_021df218(void* obj);
    void func_ov023_021df558(void* obj);
}

struct DataStruct021e0690 {
    unsigned char pad[0x14];
    struct Container020e0310* field14;
};
extern struct DataStruct021e0690 data_ov023_021ff9e0;

struct BitField021e0690 {
    unsigned int low4 : 4;
};

// USA: func_ov023_021e0690  (semantic: ReleaseListEntryAndFinalizeDisplay_021e0690)
extern "C" ARM int func_ov023_021e0690(void* obj_) {
    char* obj = (char*)obj_;
    int listPtr = (int)BackgroundLoader::GetInstance();
    unsigned short flags = *(unsigned short*)(obj + 0x774);
    if ((flags & 0x1000) || ((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(*(int*)(obj + 0x740)))) {
        memset(obj + 0x630, 0, 0x100);
        flags = *(unsigned short*)(obj + 0x774);
        if (flags & 0x1000) {
            char* s = (char*)GetFieldByKey020e0434(data_ov023_021ff9e0.field14, 0x29);
            strcpy(obj + 0x630, s);
        } else {
            int out1, out2;
            ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(*(int*)(obj + 0x740)), (void**)(&out1), (unsigned int*)(&out2));
            if (out1 != 0 && out2 != 0) {
                int v = *(short*)(obj + 0x770);
                func_020e046c(obj + 0x630, (void*)out1, (void*)out2, v);
            }
            ((BackgroundLoader*)(listPtr))->RemoveTask((int)(*(int*)(obj + 0x740)));
            *(int*)(obj + 0x740) = -1;
        }

        ClearStruct16(obj + 0x6c);
        ResetAndDetach020dfc6c((struct Struct020dfc40*)(obj + 0x8c));
        ClearStruct16(obj + 0x7c);
        ResetAndDetach020dfc6c((struct Struct020dfc40*)(obj + 0xa4));

        void* p = *(void**)(obj + 0x4c);
        if (p == NULL) {
            return -1;
        }

        struct BitField021e0690* bf = (struct BitField021e0690*)((char*)p + 8);
        int cond = (bf->low4 <= 7) ? 1 : 0;
        if (cond) {
            func_ov023_021ddf5c(obj);
            func_ov023_021df218(obj);
            func_ov023_021df558(obj);
            return -1;
        }

        func_ov023_021df558(obj);
        flags = *(unsigned short*)(obj + 0x774);
        return (flags & 0x400) ? -1 : 9;
    }

    return (*(int*)(obj + 0x740) != -1) ? 7 : -1;
}
