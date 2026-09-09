#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* a, int b);

struct Obj0202fa00;

struct List0202fe68;

struct List0202fec8;

struct S020a13c4;
extern "C" void func_020a13c4(struct S020a13c4* p);

struct StreamHeader;
extern "C" void func_020a147c(void* param0, void* param1, struct StreamHeader* param2, int param3, int param4, unsigned short param5, unsigned char param6);

extern "C" ARM int func_020ac460(void* dst);
extern "C" void __clear(void* dst, int len);

struct Array020a15bc;
extern "C" struct Elem020a15bc* func_020a15bc(struct Array020a15bc* arr, int id);

struct Data021707c8 { void* f0; void* f4; void* f8; void* fc; };
extern Data021707c8 data_ov004_021707c8;
extern char strDataBinTtldataGp2_0217039a;
extern char strTtldataLgBin_021703af;

// Builds the list of titles the player has earned. ttldata_<LG>.bin out of data/bin/ttldata.gp2 is
// parsed into the record array at data_ov004_021707c8.fc, and ids 1 to 0x1e0 survive only if a
// record exists and the matching bit is set in the 0x3c-byte block func_020ac460 copies
// out of GetBattleStruct()+0x104+0x7400, presumably the save. 0x1e0 is the count in both
// ttldata.gp2 and ttlname.gp2, and data/bin/str_dbg_ttl_en.bin is the debug menu that grants and
// deletes them. At id 0x1e0 the bit index reaches bitmap[15] of a 15-int array, a one-word overread.
extern "C" ARM int LoadTitleDataAndBuildEarnedList(void* a) {
    void* base = func_ov011_021845f8(a, 4);
    int f4 = (int)BackgroundLoader::GetInstance();
    SafeAllocator* alloc = (SafeAllocator*)((char*)base + 4);
    data_ov004_021707c8.fc = alloc->Allocate(0x14);

    int key = ((BackgroundLoader*)(f4))->QueueLoadFileInGP2((const char*)((int)&strDataBinTtldataGp2_0217039a), (const char*)((int)&strTtldataLgBin_021703af), (SafeAllocator*)(0));
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
        func_020a13c4((S020a13c4*)data_ov004_021707c8.fc);
        func_020a147c(data_ov004_021707c8.fc, (void*)((char*)base + 4), (StreamHeader*)out1, out2, 0, 0, 0xf);
    }

    ((BackgroundLoader*)((void*)f4))->RemoveTask((int)(key));
    if (out1 == 0) {
        return 0;
    }

    data_ov004_021707c8.f8 = alloc->Allocate(0x3c0);
    memset(data_ov004_021707c8.f8, 0, 0x3c0);

    int bitmap[15];
    __clear(bitmap, 0x3c);
    func_020ac460(bitmap);

    int i, n, count;
    for (count = 0, i = 0; i < 0x1e0; i++) {
        n = i + 1;
        if (func_020a15bc((Array020a15bc*)data_ov004_021707c8.fc, (short)n)) {
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
