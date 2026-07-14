#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/FileIO.h"

void ShiftInBitOnGlobalObject(void);
void HalveGlobalObjectCounter(void);
void* Clear0x54Bytes0208247c(void* obj);
extern "C" void func_02082490(void* obj, void* addr, unsigned int size, unsigned short val, int extra);
extern "C" void func_02083cbc(void* a, void* obj, void* tail);
extern "C" void func_02083e28(void* a, int arg2);

extern char data_020f1019[];
extern int data_0211e33c;

struct Block5Words0208 { unsigned int w[5]; };
struct TailBytes0208 { unsigned char b[0x18]; };
struct Combined0208 {
    Block5Words0208 block0;
    Block5Words0208 block1;
    Block5Words0208 block2;
    TailBytes0208 tail;
};

// USA: func_02082fc4
ARM void LoadAndApplyResourceEntry02082fc4(void* a, void* b) {
    char path[0x18];
    sprintf(path, data_020f1019, *(int*)((char*)a + 0x950));
    ShiftInBitOnGlobalObject();
    unsigned int size;
    void* addr = LoadFileIntoMemory(path, &data_0211e33c, &size);
    if (addr != NULL) {
        Combined0208 local;
        Clear0x54Bytes0208247c(&local);
        unsigned short val = *(unsigned short*)((char*)a + *(int*)((char*)a + 0x950) * 2 + 0x16c);
        func_02082490(&local, addr, size, val, 0);
        func_02083cbc(a, &local, &local.tail);
        func_02083e28(a, 0);
        if (b != NULL) {
            Combined0208* dst = (Combined0208*)b;
            dst->block0 = local.block0;
            dst->block1 = local.block1;
            dst->block2 = local.block2;
            dst->tail = local.tail;
        }
    }
    HalveGlobalObjectCounter();
}
