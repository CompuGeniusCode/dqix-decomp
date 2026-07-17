#include <globaldefs.h>

int GetStateCategory_022113c0(void);
void SetGlobal0224e598IfNotNine_02211864(int a, int b);

struct StateObj022110f0 {
	char pad[0x3c];
	int field3c;
};

extern StateObj022110f0* data_ov031_0224e590;

// USA: func_ov031_022110f0
ARM void StoreOrFailState_022110f0(int value) {
	if (data_ov031_0224e590 == NULL || GetStateCategory_022113c0() != 0) {
		SetGlobal0224e598IfNotNine_02211864(9, 9 - 0xb);
		return;
	}
	data_ov031_0224e590->field3c = value;
}
