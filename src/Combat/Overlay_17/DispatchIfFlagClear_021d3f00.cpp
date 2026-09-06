#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void);
struct SearchStruct;
int TestFlagBitAt0xe(struct SearchStruct* s, int idx);
void* GetData02100044(void);
unsigned char GetField0x397cValue(struct BattleStruct* bs);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Obj021d3f00 {
    char pad0;
    unsigned char b1;
    char pad2;
    unsigned char b3;
};

struct Sub021d3f00 {
    unsigned char fA;
    unsigned char fB;
    unsigned char nibLo : 4;
    unsigned char nibHi : 4;
    unsigned char fResult;
    int fWord;
};

struct Msg021d3f00 {
    unsigned char tag;
    unsigned char pad1[3];
    struct Sub021d3f00 sub;
    unsigned char pad2[8];
};

// USA: func_ov017_021d3f00  (semantic: DispatchIfFlagClear_021d3f00)
extern "C" ARM void func_ov017_021d3f00(struct Obj021d3f00* obj, unsigned char b, unsigned char c) {
    if (!obj) return;
    struct BattleStruct* bs = GetBattleStruct();
    void* search = func_0202ae18();
    if (TestFlagBitAt0xe((struct SearchStruct*)search, 0)) return;
    void* p = GetData02100044();

    struct Msg021d3f00 msg;
    struct Sub021d3f00* sub = &msg.sub;
    msg.tag = 0x3b;
    sub->fA = obj->b1;
    sub->fB = obj->b3;
    sub->nibLo = b;
    sub->nibHi = c;
    sub->fWord = *(int*)((char*)obj + 0x48);
    sub->fResult = GetField0x397cValue(bs);
    func_0205e330(p, &msg, 0);
}
