#include <globaldefs.h>

extern int GetField260_0220d540(void);
extern "C" void _Z33ClearHandleIfStatusReady_0220ca88v(void);
extern "C" void func_ov031_0220cce4(void);
extern "C" void func_ov031_0220cf6c(void);
extern "C" void func_ov031_0220d214(void);
extern "C" void func_ov031_0220d330(void);
extern "C" void _Z22SetFieldCAndA_022134cci(int);

// USA: func_ov031_0221425c  (semantic: RunFieldTransitionAction_0221425c)
extern "C" ARM int func_ov031_0221425c(void)
{
	switch (GetField260_0220d540()) {
	case 0:
		return 1;
	case 1:
		_Z33ClearHandleIfStatusReady_0220ca88v();
		break;
	case 3:
		func_ov031_0220cce4();
		break;
	case 6:
		func_ov031_0220cf6c();
		break;
	case 9:
		func_ov031_0220d214();
		break;
	case 12:
		func_ov031_0220d330();
		break;
	case 11:
		_Z22SetFieldCAndA_022134cci(0);
		return -1;
	default:
		break;
	}
	return 0;
}
