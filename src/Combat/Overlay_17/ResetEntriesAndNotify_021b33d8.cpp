#include <globaldefs.h>

int GetData02104304Field4(void);
extern "C" void func_020301c8(int a, int b);

// USA: func_ov017_021b33d8
ARM void ResetEntriesAndNotify_021b33d8(void* obj) {
	int common = GetData02104304Field4();
	int i;
	for (i = 0; i < 0xe; i++) {
		int v = *(int*)((char*)obj + i * 4 + 0x10);
		if (v >= 0) {
			func_020301c8(common, v);
		}
	}
	*(short*)((char*)obj + 8) = -1;
	((unsigned char*)obj)[0xa] = 0;
	((unsigned char*)obj)[0xb] = 0;
	int j;
	for (j = 0; j < 0xe; j++) {
		*(int*)((char*)obj + j * 4 + 0x10) = -1;
	}
}
