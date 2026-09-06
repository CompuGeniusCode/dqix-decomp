#include <globaldefs.h>

extern "C" void func_020c9b10(void* buf);
extern "C" void func_ov031_02209e28(void* data, int len);
ARM int IsGlobal0224e598Set_02211848(void);

struct StateObj02211138 {
	int field0;
	unsigned char pad4[0xc];
	int field10;
	unsigned char pad14[0x1c];
	int field30;
	int field34;
	int field38;
	unsigned char pad3c[0x4];
	void (*field40)(void*, void*, int);
	int field44;
};

extern StateObj02211138* data_ov031_0224e590;

// USA: func_ov031_02211138
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02211138(void) {
	unsigned int buf[0x20 / 4];
	func_020c9b10(buf);
	func_ov031_02209e28(buf, 0x20);
	if (IsGlobal0224e598Set_02211848()) return;

	StateObj02211138* obj = data_ov031_0224e590;
	if (obj == NULL) return;
	if (obj->field0 != 2) return;
	if (obj->field10 == 0 || obj->field30 == 0) return;

	obj->field10 = 0;
	data_ov031_0224e590->field30 = 0;
	obj = data_ov031_0224e590;
	void (*fn)(void*, void*, int) = obj->field40;
	if (fn == NULL) return;
	fn((void*)obj->field34, (void*)obj->field38, obj->field44);
}
