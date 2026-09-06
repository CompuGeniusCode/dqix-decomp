#include <globaldefs.h>

extern "C" int func_ov031_02200730(void);
extern "C" int func_ov031_02200bfc(void);

// USA: func_ov031_02201ef4
ARM int CheckOrDispatch_02201ef4(void) {
	if (func_ov031_02200730() == 0) {
		return 1;
	}
	return func_ov031_02200bfc();
}
