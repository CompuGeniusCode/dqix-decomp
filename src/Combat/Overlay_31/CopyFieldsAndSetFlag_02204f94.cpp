#include <globaldefs.h>

extern void* data_ov031_022496a4;
extern int data_ov031_0224c9d0;
extern int data_ov031_0224c99c;
extern int data_ov031_0224c9ac;

struct TwoWords0224c9e0_02204f94 {
	int a;
	int b;
};
extern TwoWords0224c9e0_02204f94 data_ov031_0224c9e0;

struct StructE1C0_02204f94 {
	char pad[8];
	int field8;
};
extern StructE1C0_02204f94 data_ov031_0224e1c0;

// USA: func_ov031_02204f94
ARM void CopyFieldsAndSetFlag_02204f94(void) {
	void* p = data_ov031_022496a4;
	data_ov031_0224c9d0 = *(int*)((char*)p + 4);
	data_ov031_0224c99c = *(int*)((char*)p + 8);
	data_ov031_0224c9ac = *(int*)((char*)p + 0xc);
	data_ov031_0224c9e0.a = *(int*)((char*)p + 0x10);
	data_ov031_0224c9e0.b = *(int*)((char*)p + 0x14);
	data_ov031_0224e1c0.field8 |= 2;
}
