#include <globaldefs.h>

int GetGlobal02109400(void);
int AlwaysTrue02094b4c(void);
extern "C" void _Z21BlankFunction02094b3cv(int a, int b);
extern "C" void _Z21BlankFunction02094b30v(int a, int b, int c);

// USA: func_ov003_0215dc20  (semantic: AdvanceBlankStateCounter_0215dc20)
extern "C" ARM void func_ov003_0215dc20(void* obj) {
	unsigned char* o = (unsigned char*)obj;
	unsigned char state;
	int g;
	if (o[0x3ec] == 0) return;
	state = o[0x3ed];
	if (state == 0) {
		g = GetGlobal02109400();
		_Z21BlankFunction02094b3cv(g, 0xa);
		if (o[0x3f0] != 0) {
			_Z21BlankFunction02094b30v(g, 0x1f5, 0);
		} else {
			_Z21BlankFunction02094b30v(g, 0x200, 1);
		}
		o[0x3ed] = o[0x3ed] + 1;
		return;
	}
	if (state != 1) return;
	GetGlobal02109400();
	if (AlwaysTrue02094b4c() != 0) {
		o[0x3ec] = 0;
		o[0x3ed] = 0;
	}
}
