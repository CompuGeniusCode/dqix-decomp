#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_020301c8(int a, int b);
int GetData02104304Field4(void);
unsigned int GetBg1CharBaseAddr(void);

struct Node0x20_021a5ad0;
void FillFieldWithEncoded_021a5ad0(struct Node0x20_021a5ad0* arr, int count, int val);
void ClearAndEncodeField14_021a5b08(struct Node0x20_021a5ad0* arr, int count);

struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0* obj);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(struct Cont0205d274* obj);
struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc* obj);
struct Obj0205d048;
extern "C" void func_0205d048(struct Obj0205d048* obj);

void InitFieldArenaLists_021a5b48(unsigned char* base);

// USA: func_ov017_021a5bac  (semantic: FlushPendingArenaState_021a5bac)
#pragma opt_common_subs off
extern "C" ARM void func_ov017_021a5bac(unsigned char* base) {
    if (*(int*)(base + 0x41c0) == 0) {
        return;
    }

    if (*(int*)(base + 0x41b8) != 0) {
        volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
        *dispcnt = (*dispcnt & ~0x1f00) | 0x100;

        if (*(int*)(base + 0x41bc) >= 0) {
            func_020301c8(GetData02104304Field4(), *(int*)(base + 0x41bc));
            *(int*)(base + 0x41bc) = -1;
        }

        volatile unsigned short* bldcnt = (volatile unsigned short*)0x4000050;
        *bldcnt = 0;
        volatile unsigned short* bg1cnt = (volatile unsigned short*)0x4000008;
        *bg1cnt = (*bg1cnt & ~3) | 1;

        if (*(int*)(base + 0x41b4) != 0) {
            memset((void*)GetBg1CharBaseAddr(), 0, 0x20);
            FillFieldWithEncoded_021a5ad0((struct Node0x20_021a5ad0*)(base + 0x4094), 2, 0x800);

            void* list = *(void**)(base + 0x4090);
            ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)list);
            CallFunc0204b04cOverList0x98((struct Cont0205d274*)list);
            InitEntries0205d2bc((struct Obj0205d2bc*)list);

            ClearAndEncodeField14_021a5b08((struct Node0x20_021a5ad0*)(base + 0x4094), 2);

            func_0205d048((struct Obj0205d048*)list);

            *dispcnt = (*dispcnt & ~0x1f00) | 0x1300;
        }
    }

    InitFieldArenaLists_021a5b48(base);
}
