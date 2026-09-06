#include <globaldefs.h>

extern "C" int FastIntDivide(int numer, unsigned int denom);

struct CombatTagData022305e8 {
	unsigned char unk0;
	unsigned char unk1;
	unsigned char unk2;
	unsigned char unk3;
	unsigned short field4;
};
extern struct CombatTagData022305e8 data_ov031_02290ca0;

// USA: func_ov031_022305a4
extern "C" ARM int func_ov031_022305a4(int a) {
	int div = FastIntDivide(data_ov031_02290ca0.field4, 0x1d);
	int i = 0;
	do {
		if (div == a) return i;
		i++;
		div++;
	} while (i < 4);
	return -1;
}
