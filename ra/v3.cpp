#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int DispatchNodeIfType7_02156e2c(void* a, int key);
extern "C" void* func_ov004_02156ed0(void* a, int key);
void* GetEntryFor_021570a4(void* obj, int index);
extern "C" int func_ov004_0215c0c0(void* obj);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
extern "C" int func_0202c508(void*);
struct SearchStruct;
int TestFlagBitAt0xe(struct SearchStruct* obj, int value);
void EnqueueEventTag184_021d3bbc(int a, int b, int c, int d);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov011_02184a40(void* obj, int val);

struct Struct021707d8_0215d534 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215d534 data_ov004_021707d8;

struct Combined0215d534 { unsigned int low7 : 7; unsigned int rest : 25; };

// USA: func_ov004_0215d534
ARM int ProcessNodeEventOrTick_0215d534(void* obj) {
    int mult;
    int code = DispatchNodeIfType7_02156e2c(obj, 0x5b);
    if (code < 0) return 0;

    void* state = func_0202ae18();
    if (!CheckField0NonZero((int*)state)) {
        func_ov004_0215c0c0(obj);
        goto end;
    }

    {
        void* node = func_ov004_02156ed0(obj, 0x5b);
        short field5c = *(short*)((char*)node + 0x5c);
        mult = field5c * 6;
        void* entry = GetEntryFor_021570a4(obj, code & 0xff);

        if (func_0202c508(state)) {
            struct Combined0215d534* c = (struct Combined0215d534*)((char*)entry + 4);
            unsigned char thresh = data_ov004_021707d8.ptr[0x11];
            if (thresh <= c->low7) {
                func_ov004_0215c0c0(obj);
                EnqueueEventTag184_021d3bbc(mult + code, data_ov004_021707d8.ptr[0x11], 1, 0);
                goto end;
            }
            func_ov011_021848a0(obj, 0x2367);
            goto end;
        }

        if (!TestFlagBitAt0xe((struct SearchStruct*)state, 0)) {
            char* p1 = (char*)GetBattleStruct() + 0x26c;
            char* p = p1 + 0x5d00;
            unsigned short v = *(unsigned short*)(p + 0xc);
            v = v & ~0xe000;
            *(unsigned short*)(p + 0xc) = v;
            EnqueueEventTag184_021d3bbc(mult + code, data_ov004_021707d8.ptr[0x11], 3, 0);
            func_ov011_02184a40(obj, 0x5c);
            goto end;
        }
        func_ov011_021848a0(obj, 0x2369);
    }
end:
    return 0;
}
