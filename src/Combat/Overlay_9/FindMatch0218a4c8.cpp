#include <globaldefs.h>
extern "C" int func_02001aec(int val, int key, int field5);

// USA: func_ov009_0218a4c8
ARM int FindMatch0218a4c8(int unused, int val, int key, int field5, int count) {
	int i;
	for (i = 0; i < count; i++, key++) {
		if (func_02001aec(val, key, field5) == 0) {
			return 1;
		}
	}
	return 0;
}
