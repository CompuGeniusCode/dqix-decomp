#include <globaldefs.h>

struct Struct_0205d81c;

extern void* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
extern "C" void func_0205ac40(void* a, void* b);

// USA: func_ov023_021e6a90
ARM void HandleElementSpecial17_021e6a90(void* a) {
	if (((unsigned char*)a)[0x1000 + 0x371] == 6) return;
	void* e = FindElementByC40205d81c((struct Struct_0205d81c*)((char*)a + 0xac), 0x11);
	if (!e) return;
	short ea = *(short*)((char*)e + 0xac);
	short eb = *(short*)((char*)e + 0xae);
	unsigned char* s = *(unsigned char**)((char*)a + 0x1000 + 0x364);
	*(int*)(s + 0x1f4) = ((short)(ea << 3) + 0xa) << 0xc;
	*(int*)(s + 0x1f8) = ((short)(eb << 3) + 3) << 0xc;
	void* arg0 = *(void**)((char*)a + 0x1000 + 0x35c);
	func_0205ac40(arg0, s + 0x1e0);
}
