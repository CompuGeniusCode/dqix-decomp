#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* node, int nodeId);

struct LoaderLockRef;

struct LoaderStatusRef;

struct LoaderFileRef;

struct TitleRecordArray;
extern "C" void func_020a13c4(struct TitleRecordArray* recordArray);

struct StreamHeader;
extern "C" void func_020a147c(void* param0, void* param1, struct StreamHeader* param2, int param3, int param4, unsigned short param5, unsigned char param6);

extern "C" ARM int func_020ac460(void* dst);
extern "C" void __clear(void* dst, int len);

struct TitleRecordTable;
extern "C" struct TitleRecord* func_020a15bc(struct TitleRecordTable* arr, int id);

struct TitleDataGlobals { void* unknown0; void* unknown4; void* earnedTitleIds; void* titleRecords; };
extern TitleDataGlobals data_ov004_021707c8;
extern char strDataBinTtldataGp2_0217039a;
extern char strTtldataLgBin_021703af;

// Builds the list of titles the player has earned. ttldata_<LG>.bin out of data/bin/ttldata.gp2 is
// parsed into the record array at data_ov004_021707c8.titleRecords, a 0x14-byte header holding a
// base pointer and a count that func_020a15bc searches on a 9-bit id field, and ids 1 to 0x1e0
// survive only if a record exists and the matching bit is set in the 0x3c-byte block func_020ac460
// copies out of GetBattleStruct()+0x104+0x7400, presumably the save. 0x1e0 is the count in both
// ttldata.gp2 and ttlname.gp2, and data/bin/str_dbg_ttl_en.bin is the debug menu that grants and
// deletes them. At id 0x1e0 the bit index reaches bitmap[15] of a 15-int array, a one-word overread.
// What the second 0x3c0 buffer at +0x4 and the 0x1000 buffer at +0x0 hold is not established.
extern "C" ARM int LoadTitleDataAndBuildEarnedList(void* node) {
    void* base = func_ov011_021845f8(node, 4);
    int loader = (int)BackgroundLoader::GetInstance();
    SafeAllocator* alloc = (SafeAllocator*)((char*)base + 4);
    data_ov004_021707c8.titleRecords = alloc->Allocate(0x14);

    int key = ((BackgroundLoader*)(loader))->QueueLoadFileInGP2((const char*)((int)&strDataBinTtldataGp2_0217039a), (const char*)((int)&strTtldataLgBin_021703af), (SafeAllocator*)(0));
    if (key < 0) {
        return 0;
    }
    while (!((BackgroundLoader*)((void*)loader))->GetTaskStatus((int)(key))) {
        ((BackgroundLoader*)((LoaderLockRef*)loader))->RemoveAllLocks();
    }

    if (((BackgroundLoader*)((LoaderStatusRef*)loader))->GetDetailedTaskStatus((int)(key)) != 2) {
        ((BackgroundLoader*)((void*)loader))->RemoveTask((int)(key));
        return 0;
    }

    int out1, out2;
    ((BackgroundLoader*)((LoaderFileRef*)loader))->GetLoadedFileByID((int)(key), (void**)(&out1), (unsigned int*)(&out2));
    if (out1 != 0) {
        func_020a13c4((TitleRecordArray*)data_ov004_021707c8.titleRecords);
        func_020a147c(data_ov004_021707c8.titleRecords, (void*)((char*)base + 4), (StreamHeader*)out1, out2, 0, 0, 0xf);
    }

    ((BackgroundLoader*)((void*)loader))->RemoveTask((int)(key));
    if (out1 == 0) {
        return 0;
    }

    data_ov004_021707c8.earnedTitleIds = alloc->Allocate(0x3c0);
    memset(data_ov004_021707c8.earnedTitleIds, 0, 0x3c0);

    int bitmap[15];
    __clear(bitmap, 0x3c);
    func_020ac460(bitmap);

    int titleIndex, titleId, count;
    for (count = 0, titleIndex = 0; titleIndex < 0x1e0; titleIndex++) {
        titleId = titleIndex + 1;
        if (func_020a15bc((TitleRecordTable*)data_ov004_021707c8.titleRecords, (short)titleId)) {
            int wordIdx = titleId / 32;
            int bitIdx = titleId % 32;
            if (bitmap[wordIdx] & (1 << bitIdx)) {
                ((short*)data_ov004_021707c8.earnedTitleIds)[count] = titleId;
                count++;
            }
        }
    }

    data_ov004_021707c8.unknown4 = alloc->Allocate(0x3c0);
    memset(data_ov004_021707c8.unknown4, 0, 0x3c0);
    data_ov004_021707c8.unknown0 = alloc->Allocate(0x1000);
    memset(data_ov004_021707c8.unknown0, 0, 0x1000);
    return 0;
}
