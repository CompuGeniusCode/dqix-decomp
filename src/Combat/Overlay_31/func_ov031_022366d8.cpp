#include <globaldefs.h>

extern "C" void VectorizedMemset(void* dst, int val, unsigned int len);
extern "C" void VectorizedInvertedMemcpy(void* dst, const void* src, unsigned int len);
extern "C" int func_02005a94(signed char* s);

// USA: func_ov031_022366d8
extern "C" ARM void func_ov031_022366d8(unsigned char* src3, unsigned char* out4) {
	unsigned char buf[4];
	VectorizedMemset(buf, 0, 4);

	int i = 0;
	int off = 0;
	do {
		VectorizedInvertedMemcpy(src3 + off, buf, 3);

		int j = 0;
		unsigned char* p = buf;
		for (;;) {
			if (*p != 0) break;
			j++;
			*p = ' ';
			p++;
			if (j >= 3) break;
		}

		out4[i] = (unsigned char)func_02005a94((signed char*)buf);
		i++;
		off += 3;
	} while (i < 4);
}
