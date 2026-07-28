#include <globaldefs.h>

void SetGlobal0224e598IfNotNine_02211864(int a, int b);
extern "C" int func_ov031_022113c0(void*);

struct StateObj022110f0 {
	char pad[0x3c];
	void (*field3c)(void*);
};

extern StateObj022110f0* data_ov031_0224e590;

// USA: func_ov031_022110f0  (semantic: SetCallbackIfActive_022110f0)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_022110f0(void (*callback)(void*)) {
	if (data_ov031_0224e590 != NULL && func_ov031_022113c0(data_ov031_0224e590) == 0) {
		goto store;
	}
	SetGlobal0224e598IfNotNine_02211864(9, 9 - 0xb);
	return;
store:
	data_ov031_0224e590->field3c = callback;
}
