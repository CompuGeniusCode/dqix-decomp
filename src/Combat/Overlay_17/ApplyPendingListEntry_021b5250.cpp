#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetData02104304Field4();
extern "C" int func_0202fdd0(int list, int key);
struct List0202fe68;
int LookupListValueByKey(struct List0202fe68* obj, int key);
struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);
extern "C" void func_0200f374(void* buf, int size);
struct HalfwordArray {
    unsigned short arr[12];
    unsigned short count;
};
ARM unsigned short CopyHalfwordArrayByCount(struct HalfwordArray* src, struct HalfwordArray* dst);
void* Clear12Bytes0206efc4(void* obj);
extern "C" void func_0206f230(void* a, int b, int c, int d, void* e, int f, int g, int h);
extern "C" void func_020301c8(int list, int key);
int CallFunc0202fa38ZeroPad(int a, int b, int c);

extern char data_ov017_021d7bc3;

struct Obj021b5250 {
    char pad0[8];
    void* sub;
    int key;
    unsigned char field10;
    char pad1[3];
    int field14;
};

// USA: func_ov017_021b5250  (semantic: ApplyPendingListEntry_021b5250)
extern "C" ARM void func_ov017_021b5250(struct Obj021b5250* obj) {
    GetBattleStruct();
    int list = GetData02104304Field4();
    if (!func_0202fdd0(list, obj->key)) {
        return;
    }

    if (LookupListValueByKey((struct List0202fe68*)list, obj->key) == 2) {
        int out2, out1;
        GetListEntryValues0202fec8((struct List0202fec8*)list, obj->key, &out1, &out2);
        if (out1 != 0) {
            char* sub = (char*)obj->sub;
            unsigned short buf[12];
            func_0200f374(buf, 0x18);
            short signedCount = (short)CopyHalfwordArrayByCount((struct HalfwordArray*)(sub + 0x44), (struct HalfwordArray*)buf);
            sub = (char*)obj->sub;
            Clear12Bytes0206efc4(sub + 0x2f8);
            char* sub2 = (char*)obj->sub;
            func_0206f230(sub + 0x2f8, *(int*)(sub2 + 0x10), out1, out2, buf, signedCount, *(int*)(sub2 + 0x14), obj->field14);
        }
    }

    func_020301c8(list, obj->key);
    obj->key = -1;
    obj->key = CallFunc0202fa38ZeroPad(list, (int)&data_ov017_021d7bc3, 0);
    obj->field10 = 7;
}
