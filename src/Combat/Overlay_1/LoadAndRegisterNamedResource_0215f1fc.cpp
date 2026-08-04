#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* obj);
int GetData02104304Field4();
struct SearchObj0202ff34;
int FindTableEntryByFormattedName(SearchObj0202ff34*, char*, int*, int*);
void ShiftInBitOnGlobalObject(void);
void HalveGlobalObjectCounter(void);
unsigned int LoadResourceIntoGlobalBuffer_0215a750(const char* path, void** outPtr);
extern "C" void _Z27TailCallInitEffect_021538c8Pv(void);
void InitOrClearAllocState_021538d4(int p0, void* unused1, SafeAllocator* alloc);

extern const char data_ov001_02165745[];
extern SafeAllocator* data_ov001_021658b8[8];

// USA: func_ov001_0215f1fc  (semantic: LoadAndRegisterNamedResource_0215f1fc)
extern "C" ARM int func_ov001_0215f1fc(void* param0) {
    char buf[0x20];
    int out1;
    int out2;
    SafeAllocator* allocator;
    int flag;

    void* name = func_ov017_021d612c(param0);
    if (GetBattleStruct() == NULL) {
        return 0;
    }
    sprintf(buf, data_ov001_02165745, name);
    allocator = data_ov001_021658b8[0];
    flag = 0;
    FindTableEntryByFormattedName((SearchObj0202ff34*)GetData02104304Field4(), buf, &out1, &out2);
    if (out1 == 0) {
        ShiftInBitOnGlobalObject();
        flag = 1;
        if (LoadResourceIntoGlobalBuffer_0215a750(buf, (void**)&out1) == 0) {
            HalveGlobalObjectCounter();
            return 0;
        }
    }
    void* newObj = allocator->Allocate(out2);
    if (newObj == NULL) {
        if (flag != 0) {
            HalveGlobalObjectCounter();
        }
        return 0;
    }
    memcpy(newObj, (void*)out1, out2);
    if (flag != 0) {
        HalveGlobalObjectCounter();
    }
    _Z27TailCallInitEffect_021538c8Pv();
    InitOrClearAllocState_021538d4((int)newObj, NULL, allocator);
    return 1;
}
