#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" unsigned long long GetCurrentTimestamp(void);
extern "C" void func_ov031_02200ccc(int a);
extern "C" int func_ov031_02200160(int a);

struct GlobalStruct0224c980_02203bcc {
	unsigned char field0;
	unsigned char field1;
	char pad18[0x18 - 2];
	void (*field18)(void);
	char pad48[0x48 - 0x1c];
	int (*field48)(void);
	char pad50[0x50 - 0x4c];
	int field50;
};

extern GlobalStruct0224c980_02203bcc data_ov031_0224c980;

// USA: func_ov031_02203bcc
extern "C" ARM int func_ov031_02203bcc(void) {
	data_ov031_0224c980.field18();
	int f50 = data_ov031_0224c980.field50;
	if (f50 == 0) {
		return f50;
	}
	func_ov031_02200ccc(data_ov031_0224c980.field50);
	SleepCurrentContext(0x64);
	func_ov031_02200ccc(data_ov031_0224c980.field50);
	unsigned int t0 = (unsigned int)(GetCurrentTimestamp() >> 16);
	goto checkExit;
retry:
	if (data_ov031_0224c980.field1 != 0) {
		return func_ov031_02200160(4);
	}
	SleepCurrentContext(0x64);
checkExit:
	{
		int r = data_ov031_0224c980.field48();
		if (r == 0) {
			return r;
		}
	}
	{
		unsigned int diff = (unsigned int)(GetCurrentTimestamp() >> 16) - t0;
		if ((int)diff < 0x17) {
			goto retry;
		}
		return diff;
	}
}
