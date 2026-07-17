#include <globaldefs.h>

extern void* data_ov031_0224e580;
int RegisterCallbackAndArm_0220fe44(int (*cb)(int*));
int IsField0Unchanged_0220ff18(void* obj);
void WaitForField2CNonZero_0220fea0(void);
void ClearField28SetField2C_0220fed8(void);
int HandleMsgTypeD6_0220fff8(int* obj);

// USA: func_ov031_0220fd78
ARM void BuildMsgD5AndSend_0220fd78(int payload, void* buf) {
	unsigned int* p = (unsigned int*)buf;
	p[0] = 0x14;
	p[1] = 0x44535359;
	p[2] = 0xd5;
	p[3] = 1;
	p[4] = payload;
	*(int*)((char*)data_ov031_0224e580 + 0x30) = 0;
	if (RegisterCallbackAndArm_0220fe44(HandleMsgTypeD6_0220fff8)) {
		if (IsField0Unchanged_0220ff18(buf)) {
			WaitForField2CNonZero_0220fea0();
		}
	}
	ClearField28SetField2C_0220fed8();
}
