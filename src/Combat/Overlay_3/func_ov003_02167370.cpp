#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

int GetData02104304Field4(void);
extern "C" void func_020301c8(int a, int b);
struct NotifyEntriesStruct0207f8bc;
void FlushNotifyEntries(struct NotifyEntriesStruct0207f8bc* p);
struct Struct02074bf4;
void ClearFlag0x11IfSet(struct Struct02074bf4* obj);
int func_020c4ac0(void);
extern "C" void func_020c45b0(int);
extern "C" void _Z31SetVramFieldAndDispatch020c4658t(int value);
struct List0204afb4;
void ResetRecordList0204afb4(struct List0204afb4* obj);
struct Obj0204c754;
void ResetObject0204c754(struct Obj0204c754* obj);

// USA: func_ov003_02167370  (semantic: ResetListsAndDestroyAllocators_02167370)
extern "C" ARM void func_ov003_02167370(char* obj) {
    int data4 = GetData02104304Field4();
    if (*(int*)(obj + 0x64) >= 0) {
        func_020301c8(data4, *(int*)(obj + 0x64));
        *(int*)(obj + 0x64) = -1;
    }

    volatile unsigned int* p1 = (volatile unsigned int*)0x4001010;
    p1[0] = 0;
    p1[1] = 0;

    if (*(void**)(obj + 0x10) != 0) {
        FlushNotifyEntries(*(struct NotifyEntriesStruct0207f8bc**)(obj + 0x10));
    }
    ClearFlag0x11IfSet((struct Struct02074bf4*)(obj + 0x1c));

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;
    *dispcnt = (*dispcnt & ~0x1f00) | (*(int*)(obj + 0x60) << 8);

    func_020c4ac0();
    func_020c45b0(*(int*)(obj + 0x14));
    _Z31SetVramFieldAndDispatch020c4658t(*(int*)(obj + 0x18));

    if (*(void**)(obj + 8) != 0) {
        ResetRecordList0204afb4(*(struct List0204afb4**)(obj + 8));
        *(int*)(obj + 8) = 0;
    }
    if (*(void**)(obj + 0xc) != 0) {
        ResetObject0204c754(*(struct Obj0204c754**)(obj + 0xc));
        *(int*)(obj + 0xc) = 0;
    }
    if (*(void**)(obj + 0x10) != 0) {
        FlushNotifyEntries(*(struct NotifyEntriesStruct0207f8bc**)(obj + 0x10));
        *(int*)(obj + 0x10) = 0;
    }
    if (*(int*)obj != 0) {
        *(int*)obj = 0;
    }
    if (*(int*)(obj + 4) == 0) return;

    for (int i = 0; i < 3; i++) {
        if (((SafeAllocator*)(*(char**)(obj + 4) + i * 0x14))->GetSignedAllocator() != 0) {
            ((SafeAllocator*)(*(char**)(obj + 4) + i * 0x14))->Destroy();
        }
    }
}
