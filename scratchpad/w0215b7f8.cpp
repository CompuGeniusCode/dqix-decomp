#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

int DispatchAdjustmentIfType4_02157018(void* a, int key);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void*);
extern "C" int func_ov017_021b213c(int, int);
int GetGlobalField0x1c020421a0();
extern "C" void func_0204500c(void*, const char*, int, int);
extern "C" void func_ov011_021848a0(void* obj, int val);
int GetGlobal02109400();
int AlwaysFalse02094b54();

struct Struct021707d8_0215b7f8 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215b7f8 data_ov004_021707d8;
extern char data_ov004_021703c7[];

// USA: func_ov004_0215b7f8
extern "C" ARM int func_ov004_0215b7f8(void* self) {
    if (!DispatchAdjustmentIfType4_02157018(self, 4)) return 0;

    char* battle = (char*)GetBattleStruct();
    char* bs26c = battle + 0x26c;

    if (func_0202c508(func_0202ae18())) {
        void* a = *(void**)(bs26c + 0x5d00);
        void* b = *(void**)((char*)data_ov004_021707d8.ptr + 0x18);
        if (func_ov017_021b213c((int)a, (int)b) != 0) {
            char frame[0x420];
            char* buf1 = frame + 0x220;
            char* buf2 = frame;

            int count = *(int*)(battle + 0x5000 + 0xf7c);
            memcpy(buf1, battle + 0x2180 + 0x4000, count);

            GetGlobal02109400();
            int deadA = 0x1389;
            void* deadB = buf1;
            int deadC = count;
            (void)deadA;
            (void)deadB;
            (void)deadC;
            AlwaysFalse02094b54();

            unsigned int len = strlen(battle + 0x1f80 + 0x4000);
            memcpy(buf2, battle + 0x1f80 + 0x4000, len);
            strcpy(buf2 + len, data_ov004_021703c7);

            void* g = (void*)GetGlobalField0x1c020421a0();
            func_0204500c(g, buf2, 0, 0xe3);
            *(int*)((char*)g + 0x998) = 1;
            *(int*)((char*)g + 0x99c) = 2;
            data_ov004_021707d8.ptr[0x30] = 1;
        }
    }

    int limit = *(short*)(data_ov004_021707d8.ptr + 0x3a);
    for (int i = 0; i < limit; i++);
    func_ov011_021848a0(self, limit + 0x2486);
    return 0;
}
