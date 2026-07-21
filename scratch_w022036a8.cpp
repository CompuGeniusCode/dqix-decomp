#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct StateStructOv31_022036a8 {
    unsigned char pad[0x8];
    unsigned char field8;
    unsigned char pad2[0x23];
    unsigned short field2c;
    unsigned short field2e;
    unsigned char pad3[4];
    int field34;
};

struct GlobalStruct0224c980_022036a8 { unsigned char pad[2]; unsigned short field2; };
extern GlobalStruct0224c980_022036a8 data_ov031_0224c980;

extern "C" void func_ov031_02201550(void* buf, int n, StateStructOv31_022036a8* state, int a, int b);

// USA: func_ov031_022036a8
extern "C" ARM int func_ov031_022036a8(void* buf, int count, StateStructOv31_022036a8* state, int flag) {
    unsigned int n;
    unsigned int baseVal;
    int writePos = state->field34;
    int shifted = writePos << 1;
    int rem = shifted + 4;
    if (flag) baseVal = 1; else baseVal = state->field2c;
    while (count != 0 && state->field8 == 4) {
        unsigned int cap = data_ov031_0224c980.field2;
        unsigned int cap2 = state->field2e;
        int newWritePos = state->field34;
        n = cap2;
        if (n >= baseVal) n = baseVal;
        if (cap < n) n = cap;
        if (!flag) n &= ~1;
        if ((unsigned int)count < n) n = count;
        int diff = newWritePos - writePos;
        int sum = rem + diff;
        if (sum == 0) n = 0;
        writePos = newWritePos;
        rem = sum - 1;
        if (n == 0) break;
        func_ov031_02201550(buf, n, state, 0x18, 0);
        CycleCurrentPriorityContexts();
        buf = (char*)buf + n;
        count -= n;
        baseVal -= n;
    }
    return n;
}
