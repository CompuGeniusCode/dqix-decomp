#include <globaldefs.h>

struct HdrStruct02201d58 {
	unsigned short w0;
	unsigned short w2;
};

struct AddrStruct02201d58 {
	unsigned char pad0[0xc];
	unsigned short hi;
	unsigned short lo;
};

struct SessionStruct02201d58 {
	unsigned char pad0[8];
	unsigned char type;
	unsigned char pad9;
	unsigned short fieldA;
	unsigned char pad0c[0x18 - 0xc];
	unsigned short field18;
	unsigned char pad1a[0x1c - 0x1a];
	unsigned int field1c;
};

// USA: func_ov031_02201d58
extern "C" ARM int func_ov031_02201d58(struct AddrStruct02201d58* addr, struct HdrStruct02201d58* hdr, struct SessionStruct02201d58* sess) {
	int match3 = 0;
	int match2 = 0;
	int match1 = 0;
	int typeOk = (sess->type != 0xa) && (sess->type != 0xb);
	if (typeOk) {
		unsigned short expected = sess->fieldA;
		unsigned short v = hdr->w2;
		if ((unsigned short)((v >> 8) | (v << 8)) == expected) {
			match1 = 1;
		}
	}
	if (match1) {
		unsigned short expected = sess->field18;
		unsigned short v = hdr->w0;
		if ((unsigned short)((v >> 8) | (v << 8)) == expected) {
			match2 = 1;
		}
	}
	if (match2) {
		unsigned int expected = sess->field1c;
		unsigned short lo = addr->lo;
		unsigned short hi = addr->hi;
		unsigned short swLo = (unsigned short)((lo >> 8) | (lo << 8));
		unsigned short swHi = (unsigned short)((hi >> 8) | (hi << 8));
		if (((unsigned int)swHi << 16 | swLo) == expected) {
			match3 = 1;
		}
	}
	return match3;
}
