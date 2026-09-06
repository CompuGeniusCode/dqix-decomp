#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_02012fe4(void);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* obj);
extern "C" void* func_0205ec34(void);
void SetOrClearBitInArray(void* unused, unsigned char* array, int bit, int value);

struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
unsigned char GetByte0x4(char* obj);
int GetWord0x7f6c(void* obj);
int GetSelectedTableIndex(struct BattleStruct* battleStruct);

struct ScaledAccum02010240;
void ApplyScaledRateIfActive(struct ScaledAccum02010240* obj);

void EnqueueEventTag147_021cdaa0(void);
int IsField600B4Zero_021b8b54(void* obj);

struct Data02107930 { unsigned char pad0[0x94]; float accum; int tableIndex; };
Data02107930* GetData02107930(void);

float GetAccumulatedValue(struct BattleStruct* battleStruct);

struct Struct020fb3f0 { unsigned char pad0[8]; unsigned char* field8; };
struct NibbleByte0218d0ec { unsigned char lowNibble : 4; unsigned char highNibble : 4; };

// USA: func_ov017_0218d0ec  (semantic: SyncTableIndexAndAccumIfEligible_0218d0ec)
extern "C" ARM void func_ov017_0218d0ec(unsigned char* ov) {
    struct BattleStruct* bs = GetBattleStruct();
    Struct020fb3f0* p1 = (Struct020fb3f0*)func_02012fe4();
    void* p2 = func_0202ae18();

    if (GetHeadNodeIdOrMinusOne(*(struct HeadNode02046b24***)(ov + 0x3000 + 0x6fc)) == 3) return;
    if (GetByte0x4((char*)bs) == 6) return;
    if (GetWord0x7f6c(bs) == 5) return;

    NibbleByte0218d0ec* nb = (NibbleByte0218d0ec*)(p1->field8 + 0xc);
    unsigned int nibble = nb->lowNibble;
    int flagNibble = 1;
    if (nibble != 0 && nibble != 7) flagNibble = 0;

    int idx1 = GetSelectedTableIndex(bs);
    if (flagNibble != 0) {
        ApplyScaledRateIfActive((struct ScaledAccum02010240*)bs);
    }

    int idx2 = GetSelectedTableIndex(bs);
    if (func_0202c508(p2) != 0 && idx1 != idx2) {
        EnqueueEventTag147_021cdaa0();
    }

    if (GetHeadNodeIdOrMinusOne(*(struct HeadNode02046b24***)(ov + 0x3000 + 0x6fc)) == 0xa) {
        if (IsField600B4Zero_021b8b54(*(void**)(ov + 0x3000 + 0x718)) != 0) return;
    }
    if (GetHeadNodeIdOrMinusOne(*(struct HeadNode02046b24***)(ov + 0x3000 + 0x6fc)) == 4) return;
    if (GetHeadNodeIdOrMinusOne(*(struct HeadNode02046b24***)(ov + 0x3000 + 0x6fc)) == 0x16) return;

    Data02107930* d = GetData02107930();
    int prevIdx = d->tableIndex;
    if (prevIdx != GetSelectedTableIndex(bs)) {
        if (GetSelectedTableIndex(bs) == 1 || GetSelectedTableIndex(bs) == 0) {
            void* base = func_0205ec34();
            SetOrClearBitInArray(base, (unsigned char*)base + 0x8c, 0x1140, 1);
        }
    }

    d->accum = GetAccumulatedValue(bs);
    d->tableIndex = GetSelectedTableIndex(bs);
}
