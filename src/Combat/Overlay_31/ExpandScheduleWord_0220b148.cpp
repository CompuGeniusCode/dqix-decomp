#include <globaldefs.h>

// USA: func_ov031_0220b148
ARM unsigned int ExpandScheduleWord_0220b148(unsigned int t, unsigned int* w) {
	unsigned int A = w[(t + 13) & 0xf];
	unsigned int B = w[t ^ 8];
	unsigned int C = w[(t + 2) & 0xf];
	unsigned int D = w[t];
	unsigned int x = D ^ (C ^ (A ^ B));
	unsigned int rot = (x << 1) | (x >> 31);
	w[t] = rot;
	return rot;
}
