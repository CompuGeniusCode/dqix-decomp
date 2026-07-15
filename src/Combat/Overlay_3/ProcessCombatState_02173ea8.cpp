#include <globaldefs.h>

int* GetGlobal02109030(void);
void UpdateChannelStateIfEligible02093f68(char* obj);
extern "C" void func_ov003_02173b4c(void* obj);
extern "C" void func_ov003_02173bd8(void* obj);

// USA: func_ov003_02173ea8
ARM void ProcessCombatState_02173ea8(unsigned char* obj) {
	unsigned char f;
	UpdateChannelStateIfEligible02093f68((char*)GetGlobal02109030());
	f = obj[0xec];
	if (f == 0) return;
	if (f == 1) {
		if (obj[0xee] < 2) return;
	}
	if (f == 6) return;
	func_ov003_02173b4c(obj);
	func_ov003_02173bd8(obj);
}
