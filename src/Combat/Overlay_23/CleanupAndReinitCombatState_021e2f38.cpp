#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4*, unsigned int);
int GetData02104304Field4(void);
extern "C" void func_020301c8(int, int);
int GetGlobal02109400(void);
void BlankFunction02094b40(void);
extern "C" void func_02094ab0(int);
extern "C" void func_ov005_02154198(void*);
extern "C" void* func_02012fe4(void);
void SetFlagBytes02017d68(void* obj);
void DestroyTenAndOne_021e4f18(void* obj);
void EmptyDestructor0205a494(void* obj);
int GetGlobalField0x1c020421a0(void);
struct CombatSlots02045cac;
void InitCombatSlots02045cac(struct CombatSlots02045cac*);
void ReinitController02043204(char*);
extern "C" void func_02043124(int);

// USA: func_ov023_021e2f38
ARM void CleanupAndReinitCombatState_021e2f38(void* obj) {
    char* o = (char*)obj;

    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0xf);

    int data4 = GetData02104304Field4();
    if (*(int*)(o + 0x630) > 0) {
        func_020301c8(data4, *(int*)(o + 0x630));
        *(int*)(o + 0x630) = -1;
    }

    int g = GetGlobal02109400();
    BlankFunction02094b40();
    func_02094ab0(g);

    if (*(void**)(o + 0x0) != 0) {
        func_ov005_02154198(*(void**)(o + 0x0));
        *(void**)(o + 0x0) = 0;
        SetFlagBytes02017d68(func_02012fe4());
    }

    DestroyTenAndOne_021e4f18(*(void**)(o + 0x124));
    if (*(void**)(o + 0x120) != 0) {
        DestroyTenAndOne_021e4f18(*(void**)(o + 0x120));
    }
    if (*(void**)(o + 0xc8) != 0) {
        EmptyDestructor0205a494(*(void**)(o + 0xc8));
    }

    ((SafeAllocator*)(o + 0x90))->Destroy();
    ((SafeAllocator*)(o + 0x7c))->Destroy();
    ((SafeAllocator*)(o + 0x68))->Destroy();
    ((SafeAllocator*)(o + 0x54))->Destroy();
    ((SafeAllocator*)(o + 0x40))->Destroy();
    ((SafeAllocator*)(o + 0x2c))->Destroy();

    *(int*)(o + 0xc0) = 0;
    *(int*)(o + 0xc4) = 0;

    int gg = GetGlobalField0x1c020421a0();
    InitCombatSlots02045cac((struct CombatSlots02045cac*)gg);
    ReinitController02043204((char*)gg);
    func_02043124(gg);

    *(int*)((char*)gg + 0x2d8) = 0;
    *(int*)((char*)gg + 0x2dc) = 0;
    *(int*)((char*)gg + 0x2e0) = 0;
}
