#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

extern "C" int func_ov012_0218432c(int a);
struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov023_021e6e60(void* obj);
void BuildMessageC_02189c44(char* self);
struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
extern "C" int func_ov023_021e6de4(char* obj);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);
extern "C" void func_ov012_0218adac(void* obj, int a, int b, int c);
extern "C" void func_ov012_0218930c(void* obj, int a);
struct Obj021e6e20;
int TestFlagsAndActiveElement2_021e6e20(struct Obj021e6e20* obj);
extern int data_02108760;

// USA: func_ov012_02186fd8  (semantic: AdvanceTagStateWithMessage_02186fd8)
extern "C" ARM void func_ov012_02186fd8(char* base) {
    unsigned char state = *(unsigned char*)(base + 0x1000 + 0x370);
    if (state == 0) {
        *(unsigned char*)(base + 0x1000 + 0x3a0) = 0;
        int ret = func_ov012_0218432c(1);
        *(int*)(base + 0x1000 + 0x3e0) = ret;
        if (ret < 0) {
            *(int*)(base + 0x1000 + 0x3e0) = 0;
        }

        FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(base + 0xac), 0, 3);
        func_ov023_021e6e60(base);
        BuildMessageC_02189c44(base);

        (*(unsigned char*)(base + 0x1000 + 0x370))++;
        return;
    }
    if (state != 1) return;

    *(unsigned char*)(base + 0x1000 + 0x3a0) = 1;
    int sum = GetActiveScaledSum0205d794((struct Struct_0205c570*)(base + 0xac));
    *(int*)(base + 0x1000 + 0x3e0) = sum;

    if (func_ov023_021e6de4(base) != 0) {
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);

        BattleStruct* bs = GetBattleStruct();
        int key = (short)(*(int*)(base + 0x1000 + 0x3e0) + 0x27d8);
        void* name = FindEntryByKey((struct TableA68*)(base + 0x133c), key);
        char* entry = (char*)bs + 0x569c;

        memset(base + 0x1440, 0, 0x40);
        memcpy(base + 0x1440, name, strlen((char*)name));

        int tagVal = *(int*)(base + 0x1000 + 0x3e0) + 0xc8;
        unsigned int existingField = *(unsigned int*)(entry + 4) & 0xfff801ff;
        *(unsigned int*)(entry + 4) = existingField | ((unsigned int)(tagVal << 22) >> 13);

        func_ov012_0218adac(base, 0, -1, 0);
        func_ov012_0218930c(base, 0);
    } else {
        if (TestFlagsAndActiveElement2_021e6e20((struct Obj021e6e20*)base) != 0) {
            func_ov012_0218930c(base, 1);
        }
    }
}
