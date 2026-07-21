#include <globaldefs.h>

struct Inner0222c660 { unsigned char pad0[0x51]; unsigned char field51; unsigned char pad1[0x56 - 0x52]; unsigned char field56; };
struct Struct0222c660 { unsigned char pad[2]; unsigned short field2; Inner0222c660* field4; };
extern Struct0222c660 data_ov031_02290c8c;

int HwDivideRemainder(int numer, int denom);

// USA: func_ov031_0222c660
extern "C" ARM void func_ov031_0222c660(void) {
	int rem = HwDivideRemainder(data_ov031_02290c8c.field2, 0x1c);
	int base = 0x36 - rem;
	int count = data_ov031_02290c8c.field4->field51;
	if (count > 5) count = 5;
	int idx = 0;
	if (idx < count) {
		do {
			int* p10 = *(int**)((char*)data_ov031_02290c8c.field4 + 0x10 + idx * 4);
			*p10 = (*p10 & 0xfe00ff00) | ((base - 2) & 0xff) | 0xb30000;
			int* p24 = *(int**)((char*)data_ov031_02290c8c.field4 + 0x24 + idx * 4);
			idx++;
			int nextBase = base + 0x1c;
			*p24 = (*p24 & 0xfe00ff00) | ((base + 1) & 0xff) | 0xd20000;
			base = nextBase;
		} while (idx < count);
	}
	data_ov031_02290c8c.field4->field56 = 1;
}
