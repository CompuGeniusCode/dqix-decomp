#include <globaldefs.h>

int GetData02104304Field4();
extern "C" void func_020301c8(int, int);

struct HandleState_02188d10 {
	char pad14[0x16];
	short state;
	int handle;
	int field1c;
};

// USA: func_ov014_02188d10
ARM int ResetHandle_02188d10(struct HandleState_02188d10* s) {
	int t = GetData02104304Field4();
	if (s->handle >= 0) {
		func_020301c8(t, s->handle);
		s->handle = -1;
	}
	s->state = 0;
	s->field1c = 0;
	return 1;
}
