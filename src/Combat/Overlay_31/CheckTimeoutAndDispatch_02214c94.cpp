#include <globaldefs.h>

unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _ll_udiv(unsigned long long dividend, unsigned int divisor, unsigned int flag);
extern "C" int func_ov031_02214fc8(void* obj, int mode);
extern "C" int func_ov031_022151b0(void*, void*, int, int);

extern int data_ov031_02245fb0;
extern int data_ov031_02245fb8;

// USA: func_ov031_02214c94  (semantic: CheckTimeoutAndDispatch_02214c94)
extern "C" ARM int func_ov031_02214c94(char* obj) {
	unsigned long long diff = GetCurrentTimestamp() - *(unsigned long long*)(obj + 0xcb0);
	unsigned long long quotient = _ll_udiv(diff << 6, 0x82ea, 0);
	if (quotient < 300) goto ret3;

	*(signed char*)(obj + 0xd11) = *(signed char*)(obj + 0xd11) + 2;
	if (*(signed char*)(obj + 0xd11) >= 13) {
		return func_ov031_02214fc8(obj, 3);
	}

	*(unsigned long long*)(obj + 0xcb0) = GetCurrentTimestamp();
	func_ov031_022151b0(&data_ov031_02245fb0, &data_ov031_02245fb8, *(signed char*)(obj + 0xd11), 0x200000);
ret3:
	return 3;
}
