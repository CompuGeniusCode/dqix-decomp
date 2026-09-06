#include <globaldefs.h>

int IsMaskComplementSet_02200754(unsigned int a);
int IsHighNibbleE_02200790(unsigned int v);

struct GlobalStruct0224c980_022007a4 {
	char pad[0x50];
	int field50;
};
extern GlobalStruct0224c980_022007a4 data_ov031_0224c980;

// USA: func_ov031_022007a4  (semantic: IsIdAllowed_022007a4)
extern "C" ARM int func_ov031_022007a4(int id) {
	int cur = data_ov031_0224c980.field50;
	int allowed = 1;
	int stageB = 1;
	int stageA = 1;
	int fieldOk = 1;
	if (cur != 0 && id != cur) fieldOk = 0;
	if (!fieldOk) {
		if (id != 0x7f000001) stageA = 0;
	}
	if (!stageA) {
		if (IsMaskComplementSet_02200754(id) == 0) stageB = 0;
	}
	if (!stageB) {
		if (IsHighNibbleE_02200790(id) == 0) allowed = 0;
	}
	return allowed;
}
