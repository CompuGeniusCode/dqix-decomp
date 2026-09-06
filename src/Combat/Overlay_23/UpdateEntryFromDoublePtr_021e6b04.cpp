#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;
extern void* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
extern "C" int func_0205ac40(void*, void*);

// USA: func_ov023_021e6b04
ARM void UpdateEntryFromDoublePtr_021e6b04(char* base) {
	if (*(unsigned char*)(base + 0x1000 + 0x371) != 0xe) return;
	if (*(unsigned char*)(base + 0x1000 + 0x370) >= 0xa) return;

	void* elem = FindElementByC40205d81c((struct Struct_0205d81c*)(base + 0xac), 0xe);
	if (elem == NULL) return;

	void *p1 = *(void**)(base + 0x0);
	void *p2 = *(void**)((char*)p1 + 0x0);
	if (p2 == NULL) return;

	unsigned char fieldE = *((unsigned char*)p2 + 0xe);
	char *arrBase = *(char**)(base + 0x1000 + 0x364);
	char *entry = arrBase + (fieldE + 15) * 0x28;
	short v0 = *(short*)((char*)p2 + 0x0);
	short v2 = *(short*)((char*)p2 + 0x2);
	*(int*)(entry + 0x14) = v0 << 0xc;
	*(int*)(entry + 0x18) = v2 << 0xc;
	*(unsigned char*)(entry + 0x26) = 0;

	func_0205ac40(*(void**)(base + 0x1000 + 0x35c), entry);
}
