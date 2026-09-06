#include <globaldefs.h>

typedef void (*HandlerFn_02216a2c)(void *a, void *b, int c);

struct Struct0224e5e8_02216a2c {
	char pad[8];
	void *field8;
};
extern struct Struct0224e5e8_02216a2c data_ov031_0224e5e8;
extern void *data_ov031_02249ba8;
extern "C" void func_ov031_022183b4(void);

// USA: func_ov031_02216a2c
ARM void InvokeHandlerAndClear_02216a2c(void) {
	void *base = data_ov031_0224e5e8.field8;
	if (base == 0) return;
	char *b1000 = (char*)base + 0x1000;
	int flag = *(int*)(b1000 + 0x314);
	HandlerFn_02216a2c fp = *(HandlerFn_02216a2c*)(b1000 + 0x210);
	if (flag != 0) {
		func_ov031_022183b4();
	}
	fp(&data_ov031_02249ba8, data_ov031_0224e5e8.field8, 0);
	data_ov031_0224e5e8.field8 = 0;
}
