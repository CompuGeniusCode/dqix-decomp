#include <globaldefs.h>
#include "Combat/Overlay_1/EventArgs.h"

extern "C" int func_ov017_021d60f4(void* p);
extern "C" void* func_ov001_0215ab20(int idx);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_0219b43c(int g, int id2, EventVec3* vec, int flag3, int flag4);

// USA: func_ov001_0215fe50
ARM int EnqueueEventWithVec3AndFlags_0215fe50(char* self, int mode) {
	int id2;
	int key;
	int flag3;
	int flag4;
	key = func_ov017_021d60f4(self);
	{
		char* self8 = self + 0x8;
		self = self + 0x10;
		id2 = func_ov017_021d60f4(self8);
	}
	void* node = func_ov001_0215ab20(key);
	if (node == 0) return 0;
	EventVec3 vec = *(EventVec3*)((char*)node + 0x74);
	flag3 = 0;
	flag4 = 0;
	if (mode >= 3) {
		flag3 = func_ov017_021d60f4(self);
		self = self + 0x8;
	}
	if (mode >= 4) {
		flag4 = func_ov017_021d60f4(self);
	}
	int g = func_ov017_0218b5b0();
	func_ov017_0219b43c(g, id2, &vec, flag3, flag4);
	return 1;
}
