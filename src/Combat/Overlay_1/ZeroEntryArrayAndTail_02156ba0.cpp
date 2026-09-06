#include <globaldefs.h>

struct Entry02156ba0 {
	unsigned int a;
	unsigned int b;
	unsigned int mat[4][3];
};

struct Buf02156ba0 {
	struct Entry02156ba0 entries[16];
	unsigned int w0;
	unsigned int w1;
	unsigned int w2;
	unsigned int pad[3];
	unsigned int w3;
};

// USA: func_ov001_02156ba0
ARM void ZeroEntryArrayAndTail_02156ba0(struct Buf02156ba0* buf) {
	int i, j;
	for (i = 0; i < 16; i++) {
		buf->entries[i].a = 0;
		buf->entries[i].b = 0;
		for (j = 0; j < 3; j++) {
			buf->entries[i].mat[0][j] = 0;
			buf->entries[i].mat[1][j] = 0;
			buf->entries[i].mat[2][j] = 0;
			buf->entries[i].mat[3][j] = 0;
		}
	}
	buf->w0 = 0;
	buf->w1 = 0;
	buf->w2 = 0;
	buf->w3 = 0;
}
