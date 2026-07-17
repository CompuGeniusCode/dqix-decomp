#include <globaldefs.h>

// USA: func_ov031_02207e90
ARM int ParseEncodedDate_02207e90(unsigned char* s, int era) {
	unsigned char b1 = s[1];
	unsigned char b0 = *s;
	s += 2;
	unsigned int century = b0 * 10 + b1 - 0x210;
	int year;
	if (era == 0x17) {
		if (century < 50) {
			year = century + 0x7d0;
		} else {
			year = century + 0x36c + 0x400;
		}
	} else {
		unsigned char c1 = s[1];
		unsigned char c0 = *s;
		s += 2;
		int yy2 = c0 * 10 + c1 - 0x210;
		year = century * 100 + yy2;
	}
	unsigned char m1 = s[1];
	unsigned char m0 = s[0];
	unsigned char d1 = s[3];
	unsigned char d0 = s[2];
	int month = m0 * 10 + m1 - 0x210;
	int combined = (year << 16) + (month << 8);
	int day = d0 * 10 + d1 - 0x210;
	return combined + day;
}
