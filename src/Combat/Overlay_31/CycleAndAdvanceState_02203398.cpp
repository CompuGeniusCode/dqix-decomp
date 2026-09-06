#include <globaldefs.h>

struct Struct0_02203398 {
	char pad[0x8];
	unsigned char field0x8;
};

extern "C" int func_ov031_02201f10(int, int, int);
void CycleCurrentPriorityContexts();

int TailCallType17_02201f98(int, int);
int TailCallType16_02201f84(int, int);

// USA: func_ov031_02203398
ARM void CycleAndAdvanceState_02203398(Struct0_02203398* obj) {
	CycleCurrentPriorityContexts();
	unsigned char field8 = obj->field0x8;
	if (field8 == 3 || field8 == 4) {
		TailCallType17_02201f98((int)obj, 0x19);
		obj->field0x8 = 7;
	} else if (field8 != 0) {
		TailCallType16_02201f84((int)obj, 0x1a);
	}
}
