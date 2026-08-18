#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* a, int b);

struct Obj0202fa00;

struct List0202fe68;

struct List0202fec8;

struct S020a13c4;
void ClearStruct020a13c4(struct S020a13c4* p);

struct StreamHeader;
void SetupGlobalAndRunScript020a147c(void* param0, void* param1, struct StreamHeader* param2, int param3, int param4, unsigned short param5, unsigned char param6);

ARM int LoadBattleBlock020ac460(void* dst);
extern "C" void func_0200f374(void* dst, int len);

struct Array020a15bc;
struct Elem020a15bc* FindElementByField020a15bc(struct Array020a15bc* arr, int id);

struct Data021707c8 { void* f0; void* f4; void* f8; void* fc; };
extern Data021707c8 data_ov004_021707c8;
extern char data_ov004_0217039a;
extern char data_ov004_021703af;

// USA: func_ov004_021567f8  (semantic: AllocateAndScanBits_021567f8)
extern "C" ARM int func_ov004_021567f8(void* a) {
    void* base = func_ov011_021845f8(a, 4);
    int f4 = (int)BackgroundLoader::GetInstance();
    SafeAllocator* alloc = (SafeAllocator*)((char*)base + 4);
    data_ov004_021707c8.fc = alloc->Allocate(0x14);

    int key = ((BackgroundLoader*)(f4))->QueueLoadFileInGP2((const char*)((int)&data_ov004_0217039a), (const char*)((int)&data_ov004_021703af), (SafeAllocator*)(0));
    if (key < 0) {
        return 0;
    }
    while (!((BackgroundLoader*)((void*)f4))->GetTaskStatus((int)(key))) {
        ((BackgroundLoader*)((Obj0202fa00*)f4))->RemoveAllLocks();
    }

    if (((BackgroundLoader*)((List0202fe68*)f4))->GetDetailedTaskStatus((int)(key)) != 2) {
        ((BackgroundLoader*)((void*)f4))->RemoveTask((int)(key));
        return 0;
    }

    int out1, out2;
    ((BackgroundLoader*)((List0202fec8*)f4))->GetLoadedFileByID((int)(key), (void**)(&out1), (unsigned int*)(&out2));
    if (out1 != 0) {
        ClearStruct020a13c4((S020a13c4*)data_ov004_021707c8.fc);
        SetupGlobalAndRunScript020a147c(data_ov004_021707c8.fc, (void*)((char*)base + 4), (StreamHeader*)out1, out2, 0, 0, 0xf);
    }

    ((BackgroundLoader*)((void*)f4))->RemoveTask((int)(key));
    if (out1 == 0) {
        return 0;
    }

    data_ov004_021707c8.f8 = alloc->Allocate(0x3c0);
    memset(data_ov004_021707c8.f8, 0, 0x3c0);

    int bitmap[15];
    func_0200f374(bitmap, 0x3c);
    LoadBattleBlock020ac460(bitmap);

    int i, n, count;
    for (count = 0, i = 0; i < 0x1e0; i++) {
        n = i + 1;
        if (FindElementByField020a15bc((Array020a15bc*)data_ov004_021707c8.fc, (short)n)) {
            int wordIdx = n / 32;
            int bitIdx = n % 32;
            if (bitmap[wordIdx] & (1 << bitIdx)) {
                ((short*)data_ov004_021707c8.f8)[count] = n;
                count++;
            }
        }
    }

    data_ov004_021707c8.f4 = alloc->Allocate(0x3c0);
    memset(data_ov004_021707c8.f4, 0, 0x3c0);
    data_ov004_021707c8.f0 = alloc->Allocate(0x1000);
    memset(data_ov004_021707c8.f0, 0, 0x1000);
    return 0;
}
