#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetData02104304Field4();
extern "C" void* func_0202ae18(void);
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
struct ZeroWordAndByte0206ee60Struct;
void ZeroWordAndByte0206ee60(struct ZeroWordAndByte0206ee60Struct* obj);
struct StreamHeader;
void RegisterCallbackWithArgsAndRunScript(void* a, void* b, struct StreamHeader* c, int d, void* e, short f);
extern "C" void func_020301c8(int list, int key);
int CallFunc0202fa38ZeroPad(int a, int b, int c);
extern "C" void func_ov017_021b5648(void* obj);

extern char data_ov017_021d7bdc;

struct Obj021b5348 {
    char pad0[8];
    void* sub;
    int key;
    unsigned char field10;
};

struct Sub021b5348 {
    char pad0[0x308];
    unsigned char field308;
};

// USA: func_ov017_021b5348  (semantic: ApplyPendingListEntryAndRunScript_021b5348)
extern "C" ARM void func_ov017_021b5348(struct Obj021b5348* obj) {
    void* subEarly;
    GetBattleStruct();
    int list = GetData02104304Field4();
    func_0202ae18();
    if (!func_0202fdd0(list, obj->key)) {
        return;
    }

    subEarly = obj->sub;
    if (LookupListValueByKey((struct List0202fe68*)list, obj->key) == 2) {
        int out2, out1;
        GetListEntryValues0202fec8((struct List0202fec8*)list, obj->key, &out1, &out2);
        if (out1 != 0) {
            char* sub = (char*)obj->sub;
            unsigned short buf[12];
            func_0200f374(buf, 0x18);
            short signedCount = (short)CopyHalfwordArrayByCount((struct HalfwordArray*)(sub + 0x44), (struct HalfwordArray*)buf);
            ZeroWordAndByte0206ee60((struct ZeroWordAndByte0206ee60Struct*)((char*)subEarly + 0x304));
            void* ptrB = *(void**)((char*)obj->sub + 0x10);
            RegisterCallbackWithArgsAndRunScript((char*)subEarly + 0x304, ptrB, (struct StreamHeader*)out1, (short)out2, buf, signedCount);
        }
    }

    func_020301c8(list, obj->key);
    obj->key = -1;
    int zero = 0;
    if (((struct Sub021b5348*)subEarly)->field308 > zero) {
        obj->key = CallFunc0202fa38ZeroPad(list, (int)&data_ov017_021d7bdc, 0);
        obj->field10 = 8;
    } else {
        func_ov017_021b5648(obj);
    }
}
