#include <globaldefs.h>

#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"

int GetWord0x0(int* obj);
int GetGlobalField0x1c020421a0();
void ReinitController02043204(char* obj);

struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
struct Obj020e25e8;
void ResetSelectionState020e25e8(struct Obj020e25e8* obj);

extern "C" void func_0203b19c(int obj, int value, int frames);
int CheckField0x20Positive(int* obj);
void InitFlags_021eb414(char* obj);
extern "C" void func_ov023_021eb43c(void* obj);
extern "C" void func_ov023_021eb26c(void* obj);

// USA: func_ov003_02158214  (semantic: HandleStateTransition3_02158214)
extern "C" ARM void func_ov003_02158214(void* p) {
    char* self = (char*)p;
    struct BattleStruct* bs = GetBattleStruct();
    int word0 = GetWord0x0((int*)bs);
    unsigned char state = *(unsigned char*)(self + 0x1f9);

    if (state == 0) {
        *(int*)(self + 0x32c) = 0;
        ReinitController02043204((char*)GetGlobalField0x1c020421a0());

        *(short*)(self + 0x1ee) = -1;
        *(short*)(self + 0x1ec) = *(short*)(self + 0x1ee);

        if (*(void**)(self + 0x1c) != 0 &&
            GetInnerFlagBit0020e28dc((struct Outer020e28dc*)*(void**)(self + 0x1c)) != 0) {
            ResetSelectionState020e25e8((struct Obj020e25e8*)*(void**)(self + 0x1c));
        }

        unsigned char newState = 3;
        *(unsigned char*)(self + 0x1f9) = newState;
        if (*(void**)(self + 0x204) == 0) return;
        func_0203b19c(word0, newState - 0x13, 0);
        *(unsigned char*)(self + 0x1f9) = 1;
        return;
    }

    if (state == 1) {
        if (CheckField0x20Positive((int*)word0) != 0) return;
        InitFlags_021eb414(*(char**)(self + 0x204));
        *(unsigned char*)(self + 0x1f9) = 2;
        return;
    }

    if (state == 2) {
        func_ov023_021eb43c(*(void**)(self + 0x204));
        if (*(unsigned short*)(*(char**)(self + 0x204) + 0x438) & 4) {
            func_ov023_021eb26c(*(void**)(self + 0x204));
            ((SafeAllocator*)(*(char**)(self + 0) + 0x64))->Reset();
            *(int*)(self + 0x204) = 0;
            *(int*)(self + 0x200) = 0;
            *(unsigned char*)(self + 0x1f9) = 3;
        }
        return;
    }

    if (state == 3) {
        *(unsigned char*)(self + 0x1f8) = 5;
        *(unsigned char*)(self + 0x1f9) = 0;
    }
}
