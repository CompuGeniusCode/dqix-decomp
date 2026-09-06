#include <globaldefs.h>

extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_0222cad8(int);
extern "C" void func_ov031_0222c3b4(int);
extern "C" void func_ov031_022351f8(int);
extern "C" void func_ov031_0222c8cc(void);
extern "C" void func_ov031_0222c71c(void);
void* CallWithZeroExtra_0223e218(void*, void*, void*, int);

struct StateBlock0222c918 {
	unsigned char state;
	unsigned char pad0;
	unsigned short field2;
	char* target;
};
extern StateBlock0222c918 data_ov031_02290c8c;

// USA: func_ov031_0222c918  (semantic: DispatchState_0222c918)
extern "C" ARM void func_ov031_0222c918(int cmd) {
	int doFollowup = 1;
	int state = data_ov031_02290c8c.state;
	switch (state) {
	case 0:
		if (cmd == 1) {
			if (data_ov031_02290c8c.field2 == 0) {
				data_ov031_02290c8c.state = 4;
				break;
			}
			func_ov031_02236878(0x13);
			void* result = CallWithZeroExtra_0223e218((void*)0, (void*)func_ov031_0222c71c, (void*)0, 0x78);
			*(int*)(data_ov031_02290c8c.target + 0x38) = (int)result;
			return;
		}
		if (*(unsigned char*)(data_ov031_02290c8c.target + 0x51) > 1) {
			data_ov031_02290c8c.state = state + 1;
		} else {
			doFollowup = 0;
		}
		break;
	case 1:
	case 2:
		if (cmd == 1) {
			data_ov031_02290c8c.state = state - 1;
			break;
		}
		if (*(unsigned char*)(data_ov031_02290c8c.target + 0x51) > state + 1) {
			data_ov031_02290c8c.state = state + 1;
		} else {
			doFollowup = 0;
		}
		break;
	case 3:
		if (cmd == 1) {
			data_ov031_02290c8c.state = state - 1;
			break;
		}
		func_ov031_0222cad8(cmd);
		return;
	case 4:
		if (cmd == 1) {
			doFollowup = 0;
			break;
		}
		data_ov031_02290c8c.field2 = 0;
		data_ov031_02290c8c.state = 0;
		func_ov031_0222c3b4(0);
		func_ov031_022351f8(0);
		break;
	}
	if (!doFollowup) {
		if (*(unsigned char*)(data_ov031_02290c8c.target + 0x59) != 0) return;
		func_ov031_02236878(9);
		*(unsigned char*)(data_ov031_02290c8c.target + 0x59) = 1;
		return;
	}
	func_ov031_02236878(8);
	func_ov031_0222c8cc();
}
