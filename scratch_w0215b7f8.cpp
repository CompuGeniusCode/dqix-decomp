#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

extern "C" int DispatchAdjustmentIfType4_02157018(void* a, int key);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void*);

struct Struct021707d8_0215b7f8 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215b7f8 data_ov004_021707d8;

extern "C" int func_ov017_021b213c(int, int);
int GetGlobal02109400(void);
extern "C" int AlwaysFalse02094b54(int, int, void*, int);
int GetGlobalField0x1c020421a0();
extern "C" void func_0204500c(void*, void*, int, int);
extern char data_ov004_021703c7;
extern "C" void func_ov011_021848a0(void* obj, int val);

struct MsgCtxStruct_0215b7f8 { char pad[0x998]; int f998; int f99c; };

// USA: func_ov004_0215b7f8
ARM int BuildAndSendMessageThenNotify_0215b7f8(void* obj) {
    if (!DispatchAdjustmentIfType4_02157018(obj, 4)) return 0;
    char* battle = (char*)GetBattleStruct();
    char* p = battle + 0x26c;
    void* state = func_0202ae18();
    if (func_0202c508(state)) {
        int* aPtr = (int*)(p + 0x5d00);
        unsigned char* ptr = data_ov004_021707d8.ptr;
        int a = *aPtr;
        int b = *(int*)(ptr + 0x18);
        if (func_ov017_021b213c(a, b)) {
            char buf1[0x200];
            char buf0[0x220];
            unsigned int len = *(unsigned int*)(battle + 0x5f7c);
            memcpy(buf1, battle + 0x6180, len);
            int g = GetGlobal02109400();
            AlwaysFalse02094b54(g, 0x1389, buf1, len);
            battle += 0x1f80;
            unsigned int slen = strlen(battle + 0x4000);
            memcpy(buf0, battle + 0x4000, slen);
            strcpy(buf0 + slen, &data_ov004_021703c7);
            void* ctx = (void*)GetGlobalField0x1c020421a0();
            func_0204500c(ctx, buf0, 0, 0xe3);
            ((struct MsgCtxStruct_0215b7f8*)ctx)->f998 = 1;
            ((struct MsgCtxStruct_0215b7f8*)ctx)->f99c = 2;
            data_ov004_021707d8.ptr[0x30] = 1;
        }
    }
    short v = *(short*)(data_ov004_021707d8.ptr + 0x3a);
    for (int i = 0; i < v; i++);
    func_ov011_021848a0(obj, v + 0x2486);
    return 0;
}
