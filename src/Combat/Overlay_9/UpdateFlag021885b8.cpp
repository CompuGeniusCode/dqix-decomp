#include <globaldefs.h>
extern "C" int func_ov023_021e5974(int a, int b, int c, int d, int e);

struct Struct021885b8 { char pad[0x7fc]; int field7fc; char pad2[0xd88-0x7fc-4]; int field_d88; char pad3[0xd9c-0xd88-4]; unsigned int flags; };

// USA: func_ov009_021885b8
ARM void UpdateFlag021885b8(struct Struct021885b8 *s) {
	if (s->flags & 0x2) {
		int arg1 = s->field7fc;
		int arg2 = s->field_d88;
		short arg3 = *(short*)((char*)arg2 + 0x568);
		func_ov023_021e5974(arg1, arg2, arg3, 0, 0);
		s->flags = (s->flags | 0x4) & ~0x2;
	}
}
