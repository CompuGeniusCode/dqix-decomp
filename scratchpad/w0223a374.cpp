#include <globaldefs.h>

struct Inner0223a374 { unsigned char pad[0x40]; int state; int tag; };
struct Global0223a374 { void (* volatile fn)(int, const char*); Inner0223a374* inner; };

extern Global0223a374 data_ov031_02290d18;
extern const char data_ov031_0224c4fc[];
extern const char data_ov031_0224c520[];

extern "C" int func_ov031_02239368(int);
extern "C" int func_ov031_0223a358(void);
extern "C" int func_ov031_02239954(void);
extern "C" int func_ov031_02239924(void);
extern "C" int func_ov031_02239a74(void);
extern "C" int func_ov031_02239a24(void);

// USA: func_ov031_0223a374
#pragma optimize_for_size off
ARM void HandleWifiStateEvent_0223a374(void) {
	Inner0223a374* inner = data_ov031_02290d18.inner;
	if (inner->state == 1) {
		void (*fn1)(int, const char*) = data_ov031_02290d18.fn;
		if (fn1 != NULL) {
			fn1(0x8000000, data_ov031_0224c4fc);
		}
		return;
	}

	void (*fn2)(int, const char*) = data_ov031_02290d18.fn;
	if (fn2 != NULL) {
		fn2(0x8000000, data_ov031_0224c520);
	}

	if (data_ov031_02290d18.inner->state == 6 || data_ov031_02290d18.inner->state == 5 || data_ov031_02290d18.inner->state == 4) {
		func_ov031_02239368(3);
	} else {
		func_ov031_02239368(3);
		func_ov031_0223a358();
		return;
	}
	switch (data_ov031_02290d18.inner->tag) {
		case 0:
		case 4:
			if (func_ov031_02239954() != 0) {
				return;
			}
			func_ov031_0223a358();
			return;
		case 1:
		case 5:
			if (func_ov031_02239a74() != 0) {
				return;
			}
			func_ov031_0223a358();
			return;
		case 2:
			if (func_ov031_02239924() != 0) {
				return;
			}
			func_ov031_0223a358();
			return;
		case 3:
			if (func_ov031_02239a24() != 0) {
				return;
			}
			func_ov031_0223a358();
			return;
	}
}
