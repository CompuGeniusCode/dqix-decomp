#include <globaldefs.h>

// USA: func_ov031_022005b4
extern "C" ARM unsigned int func_ov031_022005b4(unsigned char* addr, unsigned int len, unsigned int sum) {
	if ((unsigned int)addr & 1) {
		if (len > 1) {
			do {
				unsigned short v = ((unsigned int)addr[0] << 8) | addr[1];
				sum += v;
				addr += 2;
				len -= 2;
			} while (len > 1);
		}
	} else {
		unsigned short s = (unsigned short)sum;
		sum = (unsigned short)((s >> 8) | (s << 8));
		if (len > 1) {
			do {
				sum += *(unsigned short*)addr;
				addr += 2;
				len -= 2;
			} while (len > 1);
		}
		unsigned int t1 = (sum >> 8) & 0xff00ff;
		unsigned int t2 = (sum << 8) & 0xff00ff00;
		sum = t1 | t2;
		sum = (sum >> 16) | (sum << 16);
	}
	if (len != 0) {
		sum += (unsigned int)addr[0] << 8;
	}
	sum = (sum & 0xffff) + (sum >> 16);
	sum += sum >> 16;
	return (unsigned short)sum;
}
