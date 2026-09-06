#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void);
struct SearchStruct;
int TestFlagBitAt0xe(struct SearchStruct* obj, int value);

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);
unsigned char GetField0x397cValue(struct BattleStruct* battleStruct);

struct BitField021d3f00 {
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
};

struct Inner021d3f00 {
    unsigned char f0;
    unsigned char f1;
    struct BitField021d3f00 nibbles;
    unsigned char f3;
    unsigned int word48;
    unsigned char pad[8];
};

struct LocalEvt021d3f00 {
    unsigned char tag;
    unsigned char pad0[3];
    struct Inner021d3f00 fields;
};

// USA: func_ov017_021d3f00
ARM void EnqueueTag3bWithSelf_021d3f00(unsigned char* self, int a1, int a2) {
    if (self == 0) return;

    struct BattleStruct* battleStruct = GetBattleStruct();
    if (TestFlagBitAt0xe((struct SearchStruct*)func_0202ae18(), 0)) return;

    void* data = GetData02100044();
    struct LocalEvt021d3f00 buf;
    struct Inner021d3f00* p = &buf.fields;

    unsigned char s1 = self[1];
    unsigned char s3 = self[3];

    buf.tag = 0x3b;
    p->nibbles.lowNibble = a1 & 0xf;
    p->f0 = s1;
    p->nibbles.highNibble = a2 & 0xf;
    p->f1 = s3;
    p->word48 = *(unsigned int*)(self + 0x48);
    p->f3 = GetField0x397cValue(battleStruct);

    func_0205e330(data, &buf, 0);
}
