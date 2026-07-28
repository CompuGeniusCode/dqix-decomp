#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int DispatchNodeIfType7_02156e2c(void* a, int key);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
extern "C" int func_ov004_0215c0c0(void* obj);
extern "C" void* func_ov004_02156ed0(void* a, int key);
void* GetEntryFor_021570a4(void* obj, int index);
extern "C" int func_0202c508(void*);
void EnqueueEventTag184_021d3bbc(int a, int b, int c, int d);
extern "C" void func_ov011_021848a0(void* obj, int val);
struct SearchStruct;
int TestFlagBitAt0xe(struct SearchStruct* obj, int value);
extern "C" void func_ov011_02184a40(void* a, int b);

struct Struct021707d8_0215d534 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215d534 data_ov004_021707d8;

struct Node02156ed0_0215d534 { char pad[0x5c]; short field5c; };
struct Entry021570a4_0215d534 { char pad[4]; unsigned int field4 : 7; unsigned int field4rest : 25; };
struct Bs5f6c_0215d534 { char pad[0xc]; unsigned short fieldC; };

// USA: func_ov004_0215d534
extern "C" ARM int func_ov004_0215d534(void* self) {
    int idx = DispatchNodeIfType7_02156e2c(self, 0x5b);
    if (idx < 0) return 0;

    void* ctx = func_0202ae18();
    if (!CheckField0NonZero((int*)ctx)) {
        func_ov004_0215c0c0(self);
        return 0;
    }

    struct Node02156ed0_0215d534* node = (struct Node02156ed0_0215d534*)func_ov004_02156ed0(self, 0x5b);
    int mult6 = node->field5c * 6;
    struct Entry021570a4_0215d534* entry = (struct Entry021570a4_0215d534*)GetEntryFor_021570a4(self, idx & 0xff);

    if (func_0202c508(ctx)) {
        if (data_ov004_021707d8.ptr[0x11] > entry->field4) {
            func_ov011_021848a0(self, 0x2367);
        } else {
            func_ov004_0215c0c0(self);
            EnqueueEventTag184_021d3bbc(idx + mult6, data_ov004_021707d8.ptr[0x11], 1, 0);
        }
    } else {
        if (TestFlagBitAt0xe((struct SearchStruct*)ctx, 0) != 0) {
            func_ov011_021848a0(self, 0x2369);
        } else {
            char* bs26c = (char*)GetBattleStruct() + 0x26c;
            struct Bs5f6c_0215d534* p = (struct Bs5f6c_0215d534*)(bs26c + 0x5d00);
            p->fieldC &= ~0xe000;
            EnqueueEventTag184_021d3bbc(idx + mult6, data_ov004_021707d8.ptr[0x11], 3, 0);
            func_ov011_02184a40(self, 0x5c);
        }
    }

    return 0;
}
