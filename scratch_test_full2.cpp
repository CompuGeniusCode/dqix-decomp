#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Filesystem/FileIO.h"
extern "C" void* func_ov011_021845f8(void*, int);
extern "C" void* func_ov004_0215c448(void*);
extern "C" void* func_ov004_0215c474(void*);
extern "C" int InitObjWithMisc_021f6f20(void*, int, int, int, int, unsigned int);
extern "C" void ShiftInBitOnGlobalObject(void);
extern int data_0211e33c;
extern char data_ov004_021703ff;
extern "C" char* func_ov017_0218b5b0(void);
extern "C" void* AddOffset20_021f7318(void*);
extern "C" void CopyInternalFields0207df50(void*);
extern "C" void RestorePairTables0207df90(void*);
extern "C" void func_0204719c(void*);
extern "C" void Forward02047b30(void*, int, int, int);
extern "C" void BackupPairTables0207dfac(void*);
extern "C" void HalveGlobalObjectCounter(void);
extern "C" void SetField1cTo2_021f7320(void*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void AppendNodeToList_021f67ac(void*, void*);

extern "C" int ffull2(void* obj) {
    void* base = func_ov011_021845f8(obj, 6);
    if (!base) return 0;
    ((SafeAllocator*)((char*)base + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)base + 4))->Allocate(0xac);
    if (!block) return 0;
    char localbuf[0xac];
    func_ov004_0215c448(localbuf);
    memcpy(block, localbuf, 0xac);
    if (!InitObjWithMisc_021f6f20(block, (int)obj, 0x6a4, 6, 0, 0)) {
        int result = 0;
        func_ov004_0215c474(localbuf);
        return result;
    }
    ShiftInBitOnGlobalObject();
    unsigned int size;
    void* addr = LoadFileIntoMemory(&data_ov004_021703ff, &data_0211e33c, &size);
    char* base2 = func_ov017_0218b5b0() + 0x2cc;
    void* p20 = AddOffset20_021f7318(block);
    CopyInternalFields0207df50(base2);
    RestorePairTables0207df90(base2);
    func_0204719c(p20);
    if (addr) {
        Forward02047b30(p20, (int)addr, (int)size, (int)((char*)base + 4));
    }
    BackupPairTables0207dfac(base2);
    HalveGlobalObjectCounter();
    SetField1cTo2_021f7320(block);
    void* head = func_ov011_021849c8(obj);
    AppendNodeToList_021f67ac(head, block);
    int result = 0;
    func_ov004_0215c474(localbuf);
    return result;
}
