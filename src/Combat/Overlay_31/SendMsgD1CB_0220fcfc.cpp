#include <globaldefs.h>

extern void* data_ov031_0224e580;
int RegisterCallbackAndArm_0220fe44(int (*cb)(int*));
int IsField0Unchanged_0220ff18(void* obj);
void WaitForField2CNonZero_0220fea0(void);
void ClearField28SetField2C_0220fed8(void);
int HandleMsgType_0220ff34(int* obj);

struct Msg0220fcfc {
	unsigned int size;
	unsigned int magic;
	unsigned int type;
	unsigned int payload;
	unsigned int reserved;
	char pad[0x400];
};

// USA: func_ov031_0220fcfc
ARM void SendMsgD1CB_0220fcfc(void) {
	struct Msg0220fcfc msg;
	unsigned int* p = (unsigned int*)&msg;
	p[0] = 0x10;
	p[1] = 0x44535359;
	p[2] = 0xd1;
	void* val = *(void**)((char*)data_ov031_0224e580 + 0x24);
	p[3] = *(unsigned int*)((char*)val + 4);
	if (RegisterCallbackAndArm_0220fe44(HandleMsgType_0220ff34)) {
		if (IsField0Unchanged_0220ff18(&msg)) {
			WaitForField2CNonZero_0220fea0();
		}
	}
	ClearField28SetField2C_0220fed8();
}
