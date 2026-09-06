#include <globaldefs.h>

extern "C" int func_ov031_0221b780(int a0, int a1, int a2); // WaitAndRegisterHandler2_0221b780
int CheckAndCompare_0221b7fc(int a, int b, int c, int d);
extern "C" int func_ov031_0221b848(void);

struct Data0224e6a0 {
	unsigned char pad[8];
	int field8;
};
extern Data0224e6a0 data_ov031_0224e6a0;

// USA: func_ov031_0221b024
extern "C" ARM int func_ov031_0221b024(int obj, int* arr, int extra) {
	int base8 = obj;
	int i = 0;
	int base5 = data_ov031_0224e6a0.field8;

	do {
		if (arr[i] != 0) {
			do {
				func_ov031_0221b780(base5, 0x100, base8);
			} while (CheckAndCompare_0221b7fc(base8, base5, 0x100, extra) == 0);
		}
		i++;
		base8 += 0x100;
		base5 += 0x100;
	} while (i < 4);

	return func_ov031_0221b848() != 0;
}
