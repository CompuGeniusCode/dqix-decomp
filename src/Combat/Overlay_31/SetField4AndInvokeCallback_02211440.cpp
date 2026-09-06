#include <globaldefs.h>

void SetGlobal0224e598IfNotNine_02211864(int a, int b);

struct StateObj02211440 {
	int field0;
	void* field4;
	char pad[0x34];
	void (*field3c)(void*);
};

extern StateObj02211440* data_ov031_0224e590;

// USA: func_ov031_02211440
ARM void SetField4AndInvokeCallback_02211440(void* value) {
	if (data_ov031_0224e590 == NULL) return;
	data_ov031_0224e590->field4 = value;
	void (*fn)(void*) = data_ov031_0224e590->field3c;
	if (fn != NULL) {
		fn(value);
	} else {
		SetGlobal0224e598IfNotNine_02211864(9, 9 - 0xb);
	}
}
