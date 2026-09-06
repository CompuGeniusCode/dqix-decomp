#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern int data_ov031_0224e1c4;
extern int data_ov031_0224c9d0;

extern "C" int func_ov031_02206d90(void);
int Func_022050c4(void);
extern "C" void func_ov031_02200534(void);
extern void SetGlobal0224c980Field3c_02200524(int v);

extern void* data_ov031_022496a4;

struct Struct0224e1d0_02206c44 { char pad[0x1c]; int field1c; };
extern Struct0224e1d0_02206c44 data_ov031_0224e1d0;

// USA: func_ov031_02206c44
extern "C" ARM int RetryDispatchAndFinalize_02206c44(void) {
	if (data_ov031_0224e1c4 == 0) {
		data_ov031_0224e1c4 = data_ov031_0224c9d0;
	}

	int result = func_ov031_02206d90();
	if (result == -26) {
		do {
			SleepCurrentContext(100);
			result = func_ov031_02206d90();
		} while (result == -26);
	}

	int r = Func_022050c4();
	if (r >= 0) {
		func_ov031_02200534();
		SetGlobal0224c980Field3c_02200524(0);

		if (*(int*)((char*)data_ov031_022496a4 + 0x28) == 0) {
			void (*fn)(int) = *(void (**)(int))((char*)data_ov031_022496a4 + 0x1c);
			fn(data_ov031_0224e1d0.field1c);
		}
		data_ov031_022496a4 = 0;
	}
	return r;
}
