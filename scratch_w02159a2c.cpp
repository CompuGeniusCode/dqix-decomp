#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int DispatchNodeIfType7_02156e2c(void* a, int key);
void* GetEntryFor_021570a4(void* obj, int index);
extern "C" void func_ov011_021848a0(void* obj, int val);

struct Container020dedd0;
struct Element020de650_02159a2c { char pad[8]; unsigned int field8 : 4; };
extern "C" struct Container020dedd0* func_ov004_02156fd4(void* obj, int key);
struct Element020de650_02159a2c* FindElementByKey020dedd0(struct Container020dedd0* c, int key);

struct EntryStruct02159a2c { short field0; short pad2; unsigned int field4 : 7; };

struct Buf4Words_02159a2c { unsigned int w[4]; };
extern Buf4Words_02159a2c data_ov004_0216fb50;

struct PtrTarget02159a2c { char pad[0x3a]; short n; };
struct Struct021707d8_02159a2c { char pad[8]; struct PtrTarget02159a2c* ptr; };
extern Struct021707d8_02159a2c data_ov004_021707d8;

extern "C" int func_020dd4c4(signed char v, void* elem);
extern "C" int func_ov004_02159bcc(void* obj);

// USA: func_ov004_02159a2c  (semantic: TryDispatchStatEntry_02159a2c)
extern "C" ARM int TryDispatchStatEntry_02159a2c(void* obj) {
    GetBattleStruct();

    int key = DispatchNodeIfType7_02156e2c(obj, 0x5b);
    if (key < 0) return 0;

    EntryStruct02159a2c* entry = (EntryStruct02159a2c*)GetEntryFor_021570a4(obj, (unsigned char)key);
    if (!entry) return 0;

    struct Container020dedd0* container = func_ov004_02156fd4(obj, 5);
    if (!container) return 0;

    struct Element020de650_02159a2c* elem = FindElementByKey020dedd0(container, entry->field0);
    if (!elem) return 0;

    int ok = elem->field8 <= 7;
    if (ok) {
        Buf4Words_02159a2c buf = data_ov004_0216fb50;
        int i, j;
        short n = data_ov004_021707d8.ptr->n;
        for (i = 0; i < n; i++) {
            buf.w[i] = *(short*)((char*)data_ov004_021707d8.ptr + i * 2 + 0x32);
        }

        for (j = 0; j < n; j++) {
            if (!func_020dd4c4((signed char)buf.w[j], elem)) break;
        }

        if (j == n) {
            func_ov004_02159bcc(obj);
        } else {
            func_ov011_021848a0(obj, 0x38b);
        }
    } else {
        func_ov011_021848a0(obj, 0x2384);
    }
    return 0;
}
