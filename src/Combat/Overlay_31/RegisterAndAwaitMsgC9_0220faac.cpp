#include <globaldefs.h>

struct Header0220faac {
	unsigned int words[6];
	char padding[0x414 - 0x18];
};

extern void* data_ov031_0224e580;

extern "C" int func_ov031_0220fe44(int (*fn)(int*));
extern "C" int func_ov031_0220ff34(int* obj);
int IsField0Unchanged_0220ff18(void* obj);
void WaitForField2CNonZero_0220fea0(void);
void ClearField28SetField2C_0220fed8(void);

// USA: func_ov031_0220faac  (semantic: RegisterAndAwaitMsgC9_0220faac)
extern "C" ARM void func_ov031_0220faac(void) {
	Header0220faac hdr;
	unsigned int* q = (unsigned int*)&hdr;
	void* g = data_ov031_0224e580;
	q[0] = 0x10;
	q[1] = 0x44535359;
	q[2] = 0xcb;
	q[3] = *(int*)((char*)(*(void**)((char*)g + 0x24)) + 4);
	if (func_ov031_0220fe44(func_ov031_0220ff34) != 0) {
		if (IsField0Unchanged_0220ff18(&hdr) != 0) {
			WaitForField2CNonZero_0220fea0();
		}
	}
	ClearField28SetField2C_0220fed8();
}
