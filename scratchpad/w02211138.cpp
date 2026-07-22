#include <globaldefs.h>

extern "C" void func_020c9b10(void* buf);
extern "C" void func_ov031_02209e28(void* data, int len);
int IsGlobal0224e598Set_02211848(void);

struct StateObj02211138 {
	int field0;
	char pad0[0xc];
	int field10;
	char pad1[0x1c];
	int field30;
	int field34;
	int field38;
	char pad2[4];
	int (*field40)(int, int, int);
	int field44;
};
extern StateObj02211138* data_ov031_0224e590;

#pragma optimize_for_size off
// USA: func_ov031_02211138
ARM void func_ov031_02211138(void) {
	unsigned char buf[0x20];
	func_020c9b10(buf);
	func_ov031_02209e28(buf, 0x20);
	if (IsGlobal0224e598Set_02211848() != 0) return;

	StateObj02211138* p = data_ov031_0224e590;
	if (p == 0) return;
	if (p->field0 != 2) return;
	if (p->field10 == 0 || p->field30 == 0) return;

	p->field10 = 0;
	data_ov031_0224e590->field30 = 0;
	StateObj02211138* q = data_ov031_0224e590;
	int (*fn)(int, int, int) = q->field40;
	if (fn == 0) return;
	fn(q->field34, q->field38, q->field44);
}
