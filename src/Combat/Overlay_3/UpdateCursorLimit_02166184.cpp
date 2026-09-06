#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_ov003_02160c58(unsigned char* self, short* outHigh, short* outLow);
void* GetPtrField0x2a04(struct BattleStruct*);
extern "C" void func_ov003_02166220(unsigned char* self);

// USA: func_ov003_02166184  (semantic: UpdateCursorLimit_02166184)
extern "C" ARM void func_ov003_02166184(unsigned char* self) {
	short outHigh, outLow;
	unsigned char* base;
	int byteC8C;
	int limit;
	int flags;
	func_ov003_02160c58(self, &outHigh, &outLow);

	base = (unsigned char*)GetPtrField0x2a04(GetBattleStruct()) + 0x2000;
	byteC8C = base[0xc8c];
	limit = (byteC8C + 3) / 4;

	flags = *(int*)(self + 0x45c);
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

	func_ov003_02166220(self);
}
