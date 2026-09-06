#include <globaldefs.h>

int DispatchEvent_021dcef8(int p0, int p1, int p2, int p3, unsigned short p4);

extern "C" void func_ov027_021dbdec(void);

struct FieldHolder_021dcf44 {
	unsigned char pad0[8];
	unsigned char* ptr;
};

extern FieldHolder_021dcf44 data_ov027_021e33e0;

// USA: func_ov027_021dcf44
#pragma optimize_for_size off
ARM int DispatchEvent_021dcf44(int p0, int p1, int p2) {
	unsigned char* base = data_ov027_021e33e0.ptr;
	unsigned short up1 = (unsigned short)p1;
	unsigned short up2 = (unsigned short)p2;
	if (*(unsigned short*)(base + 0x528) == 0 || *(unsigned short*)(base + 0x526) == 1) {
		return 1;
	}
	unsigned short kind = *(unsigned short*)(base + 0x524);
	switch (kind) {
	case 1: {
		unsigned short p3v = (*(unsigned short*)(base + 0x52c) == 0) ? 0x3e8 : 0;
		int result = DispatchEvent_021dcef8(*(int*)(base + 0x508), p0, up1, p3v, up2);
		if (result == 2) {
			data_ov027_021e33e0.ptr[0x50c] = 1;
		}
		if (result == 2) {
			result = 0;
		}
		return result;
	}
	case 2: {
		int result = DispatchEvent_021dcef8((int)&func_ov027_021dbdec, p0, up1, 0, up2);
		if (result == 2) {
			data_ov027_021e33e0.ptr[0x50c] = 1;
		}
		if (result == 2) {
			result = 0;
		}
		return result;
	}
	default:
		return 1;
	}
}
