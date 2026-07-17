#include <globaldefs.h>

void InitSessionFields_0220321c(void);
void ResetSessionState02203190(void);
void ZeroField164_02203250(void);
void UpdateObjFromContext_022031bc(int, int, int);
extern "C" void* func_ov031_02203fdc(void*, int, int);
extern "C" void func_ov031_02203a84(void*, int);
void* FillRemainder_02204168(int, unsigned int, void*, unsigned int);

struct GlobalStruct0224c980_0220480c {
	char pad[0x20];
	int field20;
};
extern GlobalStruct0224c980_0220480c data_ov031_0224c980;
extern unsigned char data_ov031_0224ced6;

// USA: func_ov031_0220480c
ARM void SetupSessionWithBuffer_0220480c(void) {
	InitSessionFields_0220321c();
	ResetSessionState02203190();
	UpdateObjFromContext_022031bc(0x44, 0x43, data_ov031_0224c980.field20);

	void* buf = &data_ov031_0224ced6;
	void* p = func_ov031_02203fdc(buf, 7, 0);
	*(unsigned char*)p = 0xff;
	void* p2 = (unsigned char*)p + 1;
	unsigned int offset = (unsigned int)((char*)p2 - (char*)buf);
	void* end = FillRemainder_02204168(0, 0x12c, p2, offset);
	func_ov031_02203a84(buf, (int)((char*)end - (char*)buf));

	ZeroField164_02203250();
}
