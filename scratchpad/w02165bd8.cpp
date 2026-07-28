#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_ov003_02160c58(unsigned char* self, short* outHigh, short* outLow);
void* GetPtrField0x2a04(struct BattleStruct*);

extern "C" void func_ov003_02165c9c(unsigned char* self);

// USA: func_ov003_02165bd8
ARM void UpdateCursorState_02165bd8(unsigned char* self) {
    short outHigh, outLow;
    func_ov003_02160c58(self, &outHigh, &outLow);

    unsigned char byteF7C = *((unsigned char*)GetPtrField0x2a04(GetBattleStruct()) + 0xf7c);
    outLow = outLow - (byteF7C - 1);

    unsigned char* base = (unsigned char*)GetPtrField0x2a04(GetBattleStruct()) + 0x2000;
    int byteC8C = base[0xc8c];
    if (outLow != 0) {
        byteC8C += 1;
    }
    int limit = (byteC8C + 3) / 4;

    int flags = *(int*)(self + 0x45c);
    if (flags & 0x10) {
        self[0x49f] = (signed char)self[0x49f] + 1;
    } else if (flags & 0x20) {
        self[0x49f] = (signed char)self[0x49f] - 1;
    }
    if (limit <= (signed char)self[0x49f]) {
        self[0x49f] = 0;
    } else if ((signed char)self[0x49f] < 0) {
        self[0x49f] = limit - 1;
    }

    func_ov003_02165c9c(self);
}
