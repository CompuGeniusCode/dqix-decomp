#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov012_0218432c(int a);
extern "C" void func_ov023_021e6e60(void* obj);
extern "C" int func_ov023_021e6448(void* obj);
extern "C" int func_ov023_021e6de4(char* obj);
struct Obj021e6e20 { char pad[0xac]; };
int TestFlagsAndActiveElement2_021e6e20(struct Obj021e6e20* obj);
extern "C" void func_ov012_0218adac(void* self, int a, int b, int c);
extern "C" void func_ov012_0218930c(void* self, int a);
void SetupBattleTag02189d68(char* base);

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern int data_02108760;
struct BattleStruct;
struct BattleStruct* GetBattleStruct();
struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);

struct CountField0218a5f0 { unsigned short count : 5; unsigned short rest : 11; };

// USA: func_ov012_02187158  (semantic: AdvanceTagState_02187158)
extern "C" ARM void func_ov012_02187158(char* base) {
    int state = *(unsigned char*)(base + 0x1370);
    if (state == 0) {
        *(unsigned char*)(base + 0x13a0) = 0;
        *(int*)(base + 0x13e4) = 0;
        int cmpVal = func_ov012_0218432c(2);
        int i;
        for (i = 0; i < ((struct CountField0218a5f0*)(base + 0x1300 + 0xc4))->count; i++) {
            if (cmpVal == (*(signed char**)(base + 0x1000 + 0x3c0))[i]) {
                *(int*)(base + 0x1000 + 0x3e4) = i;
                break;
            }
        }
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(base + 0xac), 0, 3);
        func_ov023_021e6e60(base);
        SetupBattleTag02189d68(base);
        (*(unsigned char*)(base + 0x1370))++;
        return;
    }
    if (state != 1) return;
    *(unsigned char*)(base + 0x13a0) = 1;
    *(int*)(base + 0x13e4) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(base + 0xac));
    if (func_ov023_021e6448(base)) {
        *(int*)(base + 0x13e4) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(base + 0xac));
    }
    if (func_ov023_021e6de4(base)) {
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        struct BattleStruct* bs = GetBattleStruct();
        int val = (*(signed char**)(base + 0x1000 + 0x3c0))[*(int*)(base + 0x1000 + 0x3e4)];
        short key = (short)(val + 0x2710);
        char* name = (char*)FindEntryByKey((struct TableA68*)(base + 0x133c), key);
        char* p = (char*)bs + 0x29c + 0x5400;
        memset(base + 0x1440, 0, 0x40);
        memcpy(base + 0x1440, name, strlen(name));
        int v = *(int*)(p + 0x4);
        *(int*)(p + 0x4) = (v & 0xfff801ff) | ((val & 0x3ff) << 9);
        func_ov012_0218adac(base, 0, -1, 0);
        func_ov012_0218930c(base, 0);
        return;
    }
    if (TestFlagsAndActiveElement2_021e6e20((struct Obj021e6e20*)base)) {
        func_ov012_0218930c(base, 1);
    }
}
