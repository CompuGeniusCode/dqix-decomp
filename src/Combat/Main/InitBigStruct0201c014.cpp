#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Grotto/Main/FloorMap.h"
#include "Grotto/Main/ActiveGrottoClass.h"

void ClearStruct0201e248(void* obj);
void Init0207b98c(char* obj);

extern "C" void func_0200ee94(void* obj, int a, int b, void* cb1, void* cb2);
void* InitStructReturnSelf(void* obj);
void* ResetStructReturnSelf(void* obj);
void* NotifyThenResetNameTable(void* obj);
void* ResetNameTableThenNotify(void* obj);

extern "C" void func_020982b4(void* obj);

struct InitState0208f7ecStruct;
void InitState0208f7ec(struct InitState0208f7ecStruct* s);

struct ClearThreeWords02094d00Struct;
void ClearThreeWords02094d00(struct ClearThreeWords02094d00Struct* s);

void* ZeroInitReturn020de824(void* obj);

extern "C" void func_020134e0(void* obj);

// USA: func_0201c014
ARM void* InitBigStruct0201c014(void* obj) {
    ((SafeAllocator*)((char*)obj + 0x54))->ResetAllocatorPointer();
    ClearStruct0201e248((char*)obj + 0x6c);
    *(int*)((char*)obj + 0xf4) = 0;
    Init0207b98c((char*)obj + 0x10c);
    func_0200ee94((char*)obj + 0x498, 2, 0xac, (void*)InitStructReturnSelf, (void*)ResetStructReturnSelf);
    func_0200ee94((char*)obj + 0x600, 4, 0x88, (void*)ResetNameTableThenNotify, (void*)NotifyThenResetNameTable);
    func_020982b4((char*)obj + 0x840);
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)obj + 0x3ec + 0x2000);
    ((FloorMap*)((char*)grotto + 0x1c8))->Clear();
    grotto->Clear();
    InitState0208f7ec((struct InitState0208f7ecStruct*)((char*)obj + 0x264 + 0x2400));
    ClearThreeWords02094d00((struct ClearThreeWords02094d00Struct*)((char*)obj + 0x324 + 0x2400));
    ((SafeAllocator*)((char*)obj + 0x730 + 0x2000))->ResetAllocatorPointer();
    ZeroInitReturn020de824((char*)obj + 0x354 + 0x2400);
    func_020134e0(obj);
    return obj;
}
