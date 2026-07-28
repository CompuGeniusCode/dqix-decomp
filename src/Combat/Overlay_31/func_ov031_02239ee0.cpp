#include <globaldefs.h>

struct RngState02239ee0 { unsigned char pad[0x58]; int seed; };
struct RngGlobal02239ee0 { unsigned char pad[4]; RngState02239ee0* inner; };
extern RngGlobal02239ee0 data_ov031_02290d18;

#pragma optimize_for_size off
// USA: func_ov031_02239ee0  (semantic: PickWeightedBitIndex_02239ee0)
extern "C" ARM short func_ov031_02239ee0(unsigned short mask) {
	short foundIdx = 0;
	unsigned short count = 0;
	short idx = 0;
	do {
		if (mask & (1 << idx)) {
			foundIdx = idx + 1;
			count = count + 1;
		}
		idx++;
	} while (idx < 16);
	if (count <= 1) {
		return foundIdx;
	}

	data_ov031_02290d18.inner->seed = data_ov031_02290d18.inner->seed * 0x10dcd + 0x3039;
	unsigned char rb = (unsigned char)data_ov031_02290d18.inner->seed;
	unsigned short roll = (unsigned short)((count * rb) >> 8);

	short i = 0;
	do {
		if (mask & 1) {
			if (roll == 0) {
				return (short)(i + 1);
			}
			roll = roll - 1;
		}
		mask = mask >> 1;
		i++;
	} while (i < 16);
	return 0;
}
