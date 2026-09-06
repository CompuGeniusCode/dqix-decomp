#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/FileIO.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov004_0215c448(void* obj);
extern "C" void* func_ov004_0215c474(void* self);
int InitObjWithMisc_021f6f20(void* obj, int p1, int p3, int p4, int arg5, unsigned int arg6);
void ShiftInBitOnGlobalObject(void);
extern int data_0211e33c;
extern char data_ov004_021703ff;
extern "C" char* func_ov017_0218b5b0(void);
void* AddOffset20_021f7318(void* p);
struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void RestorePairTables0207df90(char* obj);
extern "C" void func_0204719c(void* obj);
void Forward02047b30(void* a, int b, int c, int d);
void BackupPairTables0207dfac(char* obj);
void HalveGlobalObjectCounter(void);
void SetField1cTo2_021f7320(void* p);
extern "C" void* func_ov011_021849c8(void* obj);
struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

// USA: func_ov004_0215c30c
ARM int AllocateAndRegisterNode_0215c30c(void* obj) {
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
    void* p20 = AddOffset20_021f7318(block);
    CopyInternalFields0207df50((struct Foo0207df50*)(func_ov017_0218b5b0() + 0x2cc));
    RestorePairTables0207df90(func_ov017_0218b5b0() + 0x2cc);
    func_0204719c(p20);
    if (addr) {
        Forward02047b30(p20, (int)addr, (int)size, (int)((char*)base + 4));
    }
    BackupPairTables0207dfac(func_ov017_0218b5b0() + 0x2cc);
    HalveGlobalObjectCounter();
    SetField1cTo2_021f7320(block);
    void* head = func_ov011_021849c8(obj);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)head, (struct ListNode_021f67ac*)block);

    int result = 0;
    func_ov004_0215c474(localbuf);
    return result;
}
