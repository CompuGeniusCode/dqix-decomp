#include <globaldefs.h>

void* GetData02100044(void);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021ce29c {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned char arr[4];
	unsigned char pad1[12];
};

// USA: func_ov017_021ce29c
ARM void EnqueueEventTag46_021ce29c(void) {
	void* p = GetData02100044();
	LocalEvt021ce29c buf;
	unsigned char* src = *(unsigned char**)((char*)(long)func_ov017_0218b5b0() + 0x3000 + 0xb30);
	buf.tag = 0x2e;
	unsigned char* dest = buf.arr;
	for (int i = 0; i < 4; i++) dest[i] = (src + 0x1b)[i];
	func_0205e330(p, &buf, 0);
}
