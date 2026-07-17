#include <globaldefs.h>

struct Rc4State_0220bab8 {
	unsigned char i, j;
	unsigned char s[256];
};

// USA: func_ov031_0220bab8
ARM void CryptRc4_0220bab8(Rc4State_0220bab8* st, unsigned char* data, int len) {
	int n = 0;
	int i = st->i;
	int j = st->j;
	unsigned char* s = st->s;
	if (len > 0) {
		do {
			i = (i + 1) & 0xff;
			unsigned char si = s[i];
			j = (j + si) & 0xff;
			unsigned char sj = s[j];
			s[i] = sj;
			s[j] = si;
			data[n] ^= s[(si + sj) & 0xff];
			n++;
		} while (n < len);
	}
	st->i = (unsigned char)i;
	st->j = (unsigned char)j;
}
