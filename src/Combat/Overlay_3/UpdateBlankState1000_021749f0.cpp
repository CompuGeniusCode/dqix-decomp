#include <globaldefs.h>

int GetGlobal02109400(void);
extern "C" void _Z21BlankFunction02094b34v(int, int, int, int, int);
int AlwaysTrue02094b4c(void);

// USA: func_ov003_021749f0  (semantic: UpdateBlankState1000_021749f0)
extern "C" ARM void func_ov003_021749f0(char* self) {
	if (!(*(unsigned short*)(self + 0x1046) & 0x40)) {
		return;
	}
	unsigned char state = *(unsigned char*)(self + 0x1041);
	if (state == 0) {
		int g = GetGlobal02109400();
		_Z21BlankFunction02094b34v(g, 0x1fb, 0x66, 0, 0);
		*(unsigned char*)(self + 0x1041) = *(unsigned char*)(self + 0x1041) + 1;
	} else if (state == 1) {
		GetGlobal02109400();
		if (AlwaysTrue02094b4c() != 0) {
			*(unsigned short*)(self + 0x1046) &= ~0x40;
			*(unsigned char*)(self + 0x1041) = 0;
		}
	}
}
