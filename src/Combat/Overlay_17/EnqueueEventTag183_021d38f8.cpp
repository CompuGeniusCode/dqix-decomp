#include <globaldefs.h>

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021d38f8
ARM void EnqueueEventTag183_021d38f8(unsigned char a0, unsigned char a1, unsigned char a2, unsigned char a3, int* p) {
	void* d = GetData02100044();
	unsigned char buf[0x14];
	buf[0] = 0xb7;
	unsigned char* b = buf + 4;
	b[0] = a0;
	b[1] = a1;
	b[2] = a2;
	b[3] = a3;
	*(int*)(b + 4) = *p;
	func_0205e330(d, buf, 0);
}
