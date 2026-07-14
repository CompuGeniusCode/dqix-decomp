#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct FlagWord02046708;
void* GetDataPtr02114e04_020d6c00(void);
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
int GetData02104304Field4(void);

struct List0202fe68;
int LookupListValueByKey(struct List0202fe68* obj, int key);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);

extern "C" void func_0204719c(void);
extern "C" void func_02047b40(void* a, int b, void* c);
extern "C" void func_020301c8(void* obj, int key);
extern "C" void func_0205308c(void* ctx, int val);

// USA: func_020534ac
ARM void ProcessCombatState020534ac(char* ctx) {
    int base;
    char* blockA;
    char* blockB;
    void* obj;
    void* allocated;
    int out1;
    int out2;

    if (TestFlags02046708((struct FlagWord02046708*)GetDataPtr02114e04_020d6c00(), 2)) {
        return;
    }
    if (*(unsigned char*)(ctx + 0x185) == 0) {
        return;
    }

    obj = (void*)GetData02104304Field4();

    if (LookupListValueByKey((struct List0202fe68*)obj, *(int*)(ctx + 0x194)) == 2) {
        GetListEntryValues0202fec8((struct List0202fec8*)obj, *(int*)(ctx + 0x194), &out1, &out2);
        if (out1 != 0) {
            base = *(int*)(ctx + 0x154);
            blockA = (char*)(base + 0x168);
            blockB = (char*)(base + 0x154);
            CopyInternalFields0207df50((struct Foo0207df50*)(blockA + 0x400));
            RestorePairTables0207df90(blockA + 0x400);
            allocated = ((SafeAllocator*)(blockB + 0x400))->Allocate(0x88);
            *(void**)(ctx + 0x190) = allocated;
            if (allocated != NULL) {
                func_0204719c();
                *(unsigned char*)((char*)(*(void**)(ctx + 0x190)) + 0x84) |= 4;
                func_02047b40(*(void**)(ctx + 0x190), out1, blockB + 0x400);
            }
            BackupPairTables0207dfac(blockA + 0x400);
        }
    }

    func_020301c8(obj, *(int*)(ctx + 0x194));
    *(int*)(ctx + 0x194) = -1;
    *(unsigned char*)(ctx + 0x185) = 0;

    if (*(unsigned char*)(ctx + 0x186) != 0) {
        signed char idx = *(signed char*)(ctx + 0x17d);
        char* p = ctx + (idx + 1);
        p = p + 0x100;
        func_0205308c(ctx, *(signed char*)(p + 0x78));
        *(unsigned char*)(ctx + 0x186) = 0;
    }
}
