#include <globaldefs.h>

typedef void (*Fn02219080)(void*, int, int);

struct Data0224e60c { void* field0; char pad[0x10]; int field14; };
extern Data0224e60c data_ov031_0224e60c;
extern int data_ov031_0224a05c;
extern int data_ov031_0224a06c;
extern int data_ov031_0224a088;
extern int data_ov031_0224a0a8;

extern "C" void func_ov031_022183b4(void);
void InvokeHandlerAndClear_02216a2c(void);

// USA: func_ov031_02219080  (semantic: RunPendingHandlers_02219080)
extern "C" ARM void func_ov031_02219080(void) {
	char* base = (char*)data_ov031_0224e60c.field0 + 0x1000;
	Fn02219080 fn = *(Fn02219080*)(base + 0x10c);
	if (data_ov031_0224e60c.field14 != 0) {
		func_ov031_022183b4();
		fn(&data_ov031_0224a05c, data_ov031_0224e60c.field14, 0);
		data_ov031_0224e60c.field14 = 0;
	}
	InvokeHandlerAndClear_02216a2c();
	if (data_ov031_0224e60c.field0 == 0) return;
	base = (char*)data_ov031_0224e60c.field0 + 0x1000;
	int v1 = *(int*)(base + 0x114);
	if (v1 != 0) {
		fn(&data_ov031_0224a06c, v1, 0);
		base = (char*)data_ov031_0224e60c.field0 + 0x1000;
		*(int*)(base + 0x114) = 0;
	}
	base = (char*)data_ov031_0224e60c.field0 + 0x1000;
	int v2 = *(int*)(base + 0x118);
	if (v2 != 0) {
		fn(&data_ov031_0224a088, v2, 0);
		base = (char*)data_ov031_0224e60c.field0 + 0x1000;
		*(int*)(base + 0x118) = 0;
	}
	fn(&data_ov031_0224a0a8, (int)data_ov031_0224e60c.field0, 0);
	data_ov031_0224e60c.field0 = 0;
}
