#include <globaldefs.h>

int GetData02104304Field4();
extern "C" void func_020301c8(int a, int b);

struct Obj021b4760 {
	char pad[0xc];
	int fieldc;
};

// USA: func_ov017_021b4760
ARM void ClearFieldcIfSet_021b4760(struct Obj021b4760* self) {
	int x = GetData02104304Field4();
	if (self->fieldc <= -1) {
		return;
	}
	func_020301c8(x, self->fieldc);
	self->fieldc = -1;
}
