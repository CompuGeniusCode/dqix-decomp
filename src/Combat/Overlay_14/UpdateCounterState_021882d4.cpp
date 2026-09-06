#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetWord0x0(int* obj);
void SetBothCounters(void* obj, int value, int frames);
int CheckField0x14Or0x20Positive(int* obj);

struct S021882d4 {
	unsigned char pad0[0x17a];
	unsigned char byte17a;
	unsigned char byte17b;
};

// USA: func_ov014_021882d4
ARM void UpdateCounterState_021882d4(struct S021882d4* r4) {
	int val = GetWord0x0((int*)GetBattleStruct());
	if (r4->byte17b == 0) {
		SetBothCounters((void*)val, -16, 8);
		r4->byte17b++;
		return;
	}
	if (r4->byte17b != 1) return;
	if (!CheckField0x14Or0x20Positive((int*)val)) {
		r4->byte17a = 6;
		r4->byte17b = 0;
	}
}
