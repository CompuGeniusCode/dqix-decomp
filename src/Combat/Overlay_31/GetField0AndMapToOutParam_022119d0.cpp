#include <globaldefs.h>

struct GlobalPair022119d0 {
	int field0;
	int field4;
};
extern GlobalPair022119d0 data_ov031_0224e5a4;

// USA: func_ov031_022119d0  (semantic: GetField0AndMapToOutParam_022119d0)
extern "C" ARM int func_ov031_022119d0(int *out, int *mapped) {
	if (out != 0) {
		*out = data_ov031_0224e5a4.field4;
	}
	if (mapped != 0) {
		switch (data_ov031_0224e5a4.field0) {
			case 2:
			case 3:
			case 4:
			case 5:
			case 8:
				*mapped = 6;
				break;
			case 6:
				*mapped = 3;
				break;
			case 7:
				*mapped = 4;
				break;
			case 10:
			case 11:
			case 12:
			case 13:
				*mapped = 1;
				break;
			case 1:
			case 9:
				*mapped = 7;
				break;
			case 14:
				*mapped = 5;
				break;
			case 15:
			case 17:
			case 19:
				*mapped = 6;
				break;
			case 16:
			case 18:
			case 20:
			case 21:
				*mapped = 2;
				break;
			default:
				*mapped = 0;
				break;
		}
	}
	return data_ov031_0224e5a4.field0;
}
