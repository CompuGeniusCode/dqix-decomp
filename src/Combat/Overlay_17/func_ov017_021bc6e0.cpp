#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_02012fe4(struct BattleStruct* battleStruct);
float GetAccumulatedValue(struct BattleStruct* battleStruct);

struct Src021cd6d8 {
	unsigned short f0;
	unsigned short f2;
	unsigned short f4;
	short f6;
	unsigned char f8;
	unsigned short fa;
	signed char fc;
	unsigned char pad;
	float f10;
};
void EnqueueEventTag142_021cd6d8(Src021cd6d8* src);

// USA: func_ov017_021bc6e0
extern "C" ARM void func_ov017_021bc6e0(char* self, unsigned char byteArg, int flags) {
	struct BattleStruct* battleStruct = GetBattleStruct();
	void* obj2 = func_02012fe4(battleStruct);
	Src021cd6d8 params;
	params.f0 = 0;
	params.fc = -1;
	params.f2 = 0;
	params.f4 = 0;
	params.f6 = 0;
	params.f8 = 0;
	params.fa = 0;
	params.f10 = 0.0f;
	if (!(flags & 0x800)) {
		params.f0 = *(unsigned short*)obj2;
	}
	params.f2 = *(unsigned short*)(self + 0x16);
	params.f4 = *(unsigned short*)(self + 0x18);
	params.f8 = 0;
	params.fa = *(unsigned short*)(self + 0x1c);
	params.f6 = *(short*)(self + 0x52);
	params.f10 = GetAccumulatedValue(battleStruct);
	params.fc = byteArg;
	EnqueueEventTag142_021cd6d8(&params);
}
