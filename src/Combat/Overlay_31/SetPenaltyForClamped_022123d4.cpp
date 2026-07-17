#include <globaldefs.h>

extern "C" void func_ov031_02211e08(void);
int CheckField4Eq6_02212248(void);
int GetFieldOr_02213024_02213024(void);
int GetField260_0220d540(void);
void SetGlobal0224e5a4IfNotNine(int, int);

// USA: func_ov031_022123d4
ARM int SetPenaltyForClamped_022123d4(void) {
	func_ov031_02211e08();
	if (CheckField4Eq6_02212248()) {
		unsigned int v = GetFieldOr_02213024_02213024();
		if (v == 0xff || v > 0x63) v = 0x63;
		if (GetField260_0220d540() == 0xb) {
			SetGlobal0224e5a4IfNotNine(9, 0xffff298c - v);
		} else {
			SetGlobal0224e5a4IfNotNine(8, 0xffff2d10 - v);
		}
		return 1;
	}
	return 0;
}
