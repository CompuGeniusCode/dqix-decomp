#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void func_ov031_02200ccc(int a);
extern "C" int func_ov031_02200bfc(int a);

struct GlobalStruct0224c980_02200dc8 {
	char pad[0x50];
	int field50;
};

extern GlobalStruct0224c980_02200dc8 data_ov031_0224c980;

// USA: func_ov031_02200dc8
ARM int LoopSleepAndCheck_02200dc8(int a) {
	unsigned int i = 0;
	do {
		func_ov031_02200ccc(a);
		unsigned int j = 0;
		do {
			if (data_ov031_0224c980.field50 == 0) {
				return 0;
			}
			SleepCurrentContext(100);
			int r = func_ov031_02200bfc(a);
			if (r != 0) {
				return r;
			}
			j++;
		} while (j < 20);
		i++;
	} while (i < 8);
	return 0;
}
