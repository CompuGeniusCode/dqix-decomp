#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov012_02184384(void* ptr, int idx);
extern "C" void func_ov023_021e6e60(void* obj);
extern "C" int func_ov023_021e6448(void* obj);
extern "C" int func_ov023_021e6de4(char* obj);
struct Obj021e6e20 { char pad[0xac]; };
int TestFlagsAndActiveElement2_021e6e20(struct Obj021e6e20* obj);
extern "C" void func_ov012_0218adac(void* self, int a, int b, int c);
extern "C" void func_ov012_0218930c(void* self, int a);
void SetupBattleTag0218a7a0(char* base);

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern int data_02108760;
struct BattleStruct;
struct BattleStruct* GetBattleStruct();
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);

struct StateField02188924 { unsigned short count : 5; unsigned short idx : 11; };

// USA: func_ov012_02188924  (semantic: AdvanceTagStateB_02188924)
extern "C" ARM void func_ov012_02188924(char* base) {
    int state = *(unsigned char*)(base + 0x1370);
    if (state == 0) {
        *(unsigned char*)(base + 0x13a0) = 0;
        int idx = ((struct StateField02188924*)(base + 0x1300 + 0xc4))->idx;
        void* ptr = *(void**)(base + 0x1000 + 0x3c8);
        int result = func_ov012_02184384(ptr, idx);
        *(int*)(base + 0x1000 + 0x3f0) = result;
        if (result < 0) {
            *(int*)(base + 0x1000 + 0x3f0) = 0;
        }
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(base + 0xac), 0, 3);
        func_ov023_021e6e60(base);
        SetupBattleTag0218a7a0(base);
        (*(unsigned char*)(base + 0x1370))++;
        return;
    }
    if (state != 1) return;
    *(unsigned char*)(base + 0x13a0) = 1;
    *(int*)(base + 0x13f0) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(base + 0xac));
    if (func_ov023_021e6448(base)) {
        *(int*)(base + 0x13f0) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(base + 0xac));
    }
    if (func_ov023_021e6de4(base)) {
        short* sptr = *(short**)(base + 0x1000 + 0x3c8);
        int sel = *(int*)(base + 0x1000 + 0x3f0);
        short sKey = sptr[sel];
        struct Container020e0310* c = (struct Container020e0310*)(base + 0x1344);
        char* name = (char*)GetFieldByKey020e0434(c, sKey);
        if (!name) return;
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        memset(base + 0x1400, 0, 0x40);
        memcpy(base + 0x1400, name, strlen(name));
        struct BattleStruct* bs = GetBattleStruct();
        char* p = (char*)bs + 0x29c + 0x5400;
        int v = *(int*)(p + 0x4);
        int sel2 = *(int*)(base + 0x1000 + 0x3f0);
        unsigned short* uptr = *(unsigned short**)(base + 0x1000 + 0x3c8);
        unsigned int raw = uptr[sel2];
        *(int*)(p + 0x4) = (v & 0xc007ffff) | ((raw & 0x7ff) << 19);
        int w = *(int*)((char*)bs + 0x5000 + 0x69c);
        w = (w & ~0x40000000) | 0x20000000;
        *(int*)((char*)bs + 0x5000 + 0x69c) = w;
        func_ov012_0218adac(base, 0, -1, 0);
        func_ov012_0218930c(base, 0);
        return;
    }
    if (TestFlagsAndActiveElement2_021e6e20((struct Obj021e6e20*)base)) {
        func_ov012_0218930c(base, 1);
    }
}
