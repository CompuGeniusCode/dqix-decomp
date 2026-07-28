#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/FileIO.h"

extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void* func_ov004_0215c448(void* obj);
extern "C" int func_ov023_021f6f20(void* obj, int p1, int p3, int p4, int arg5, unsigned int arg6);
extern "C" void* func_ov004_0215c474(void* self);
void ShiftInBitOnGlobalObject();
void HalveGlobalObjectCounter();
extern "C" int func_ov017_0218b5b0(void);
extern "C" void* func_ov023_021f7318(void* p);

struct Block0207df50 { unsigned int v[10]; };
struct Pair0207df50 { unsigned int v[2]; };
struct Foo0207df50 {
    struct Block0207df50 a;
    struct Block0207df50 b;
    unsigned int c;
    unsigned int d;
    struct Pair0207df50 p1;
    struct Pair0207df50 p2;
};
void CopyInternalFields0207df50(struct Foo0207df50* p);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
void Forward02047b30(void* a, int b, int c, int d);
extern "C" void func_0204719c(void* obj);
extern "C" void func_ov023_021f7320(void* p);
extern "C" void* func_ov011_021849c8(void*);

struct ListHead_021f67ac { void* first; };
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern char data_ov004_021703ff;
extern char data_0211e33c[];

// USA: func_ov004_0215c30c
extern "C" ARM int func_ov004_0215c30c(void* self) {
    void* ctx = func_ov011_021845f8(self, 6);
    if (!ctx) return 0;

    SafeAllocator* allocator = (SafeAllocator*)((char*)ctx + 4);
    allocator->GetSizeWithLargestBlockRemoved();
    void* block = allocator->Allocate(0xac);
    if (!block) return 0;

    char temp[0xac];
    func_ov004_0215c448(temp);
    memcpy(block, temp, 0xac);

    int r = func_ov023_021f6f20(block, (int)self, 0x6a4, 6, 0, 0);
    if (r == 0) {
        int ret = 0;
        func_ov004_0215c474(temp);
        return ret;
    }

    ShiftInBitOnGlobalObject();
    unsigned int size = 0;
    void* fileData = LoadFileIntoMemory(&data_ov004_021703ff, data_0211e33c, &size);

    char* obj2 = (char*)(int)func_ov017_0218b5b0() + 0x2cc;
    void* fieldPtr = func_ov023_021f7318(block);

    CopyInternalFields0207df50((struct Foo0207df50*)obj2);
    RestorePairTables0207df90(obj2);
    func_0204719c(fieldPtr);

    if (fileData != 0) {
        Forward02047b30(fieldPtr, (int)fileData, (int)size, (int)allocator);
    }

    BackupPairTables0207dfac(obj2);
    HalveGlobalObjectCounter();
    func_ov023_021f7320(block);
    void* listCtx = func_ov011_021849c8(self);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)listCtx, (struct ListNode_021f67ac*)block);

    int ret = 0;
    func_ov004_0215c474(temp);
    return ret;
}
