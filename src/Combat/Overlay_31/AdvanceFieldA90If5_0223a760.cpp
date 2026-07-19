#include <globaldefs.h>

extern unsigned char* data_ov031_02290d20;
extern "C" void func_ov031_02238b60(void);

// USA: func_ov031_0223a760
ARM int AdvanceFieldA90If5_0223a760(void) {
	if (data_ov031_02290d20[0xa90] != 5) {
		return 0;
	}
	data_ov031_02290d20[0xa90] = 6;
	func_ov031_02238b60();
	return 1;
}
