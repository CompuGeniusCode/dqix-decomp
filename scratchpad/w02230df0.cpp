#include <globaldefs.h>

extern char* GetOffset400_02235c70(void);
extern int CheckRange_0221b258(unsigned char* p);
extern "C" int func_ov031_0221b1f4(unsigned char* a, unsigned char* b);

// USA: func_ov031_02230df0
extern "C" ARM int CheckAllExtraRanges_02230df0(void) {
	unsigned char* base = (unsigned char*)GetOffset400_02235c70();
	if (base[0x40] == 0) {
		return 0;
	}
	if (base[0xf6] == 0) {
		if (!CheckRange_0221b258(base + 0xc8)) {
			if (!CheckRange_0221b258(base + 0xcc)) {
				return 0;
			}
		}
	}
	if (base[0xf5] == 0) {
		if (!CheckRange_0221b258(base + 0xc0)) {
			return 0;
		}
		if (!CheckRange_0221b258(base + 0xc4)) {
			return 0;
		}
		if (!func_ov031_0221b1f4(base + 0xc0, base + 0xf0)) {
			return 0;
		}
	}
	return 1;
}
