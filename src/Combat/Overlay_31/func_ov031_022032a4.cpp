#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/ProcessorContext.h"

extern "C" int func_ov031_02203120(void*);
extern "C" int func_ov031_02201f10(int, int, int);
unsigned long long GetCurrentTimestamp(void);

struct GlobalStruct0224c980_022032a4 {
	char pad[0x50];
	int field50;
};
extern GlobalStruct0224c980_022032a4 data_ov031_0224c980;

struct Obj_022032a4 {
	char pad0[0x4];
	int field4;
	char pad1[0x8 - 0x4 - 0x4];
	unsigned char field8;
	char pad2[0x10 - 0x8 - 0x1];
	unsigned int field10;
	char pad3[0x28 - 0x10 - 0x4];
	int field28;
};

// USA: func_ov031_022032a4
extern "C" ARM int func_ov031_022032a4(Obj_022032a4* obj) {
	unsigned int tries;
	int result28 = func_ov031_02203120(obj);
	int mode = 2;
	tries = 0;
	do {
		obj->field28 = result28;
		obj->field8 = (unsigned char)mode;
		obj->field10 = (unsigned int)(GetCurrentTimestamp() >> 16);
		func_ov031_02201f10((int)obj, mode, 0x18);

		int oldIRQ = DisableIRQInterrupts();
		if (obj->field8 == 2 && data_ov031_0224c980.field50 != 0) {
			obj->field4 = 1;
			BlockCurrentContext(NULL);
		}
		SetIRQInterruptState(oldIRQ);

		if (obj->field8 == 4) {
			return 0;
		}
		if (data_ov031_0224c980.field50 == 0) break;
		tries = tries + 1;
	} while (tries < 3);
	return 1;
}
