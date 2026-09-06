#include <globaldefs.h>

extern "C" int func_02012444(void*, int);
extern "C" int func_020e28dc(void);
extern "C" int func_020e2984(void*);
extern "C" void func_02012a84(void*, short*, short*);
extern "C" int func_02080d54(void*, int, int, int);
extern int data_02114e30;
extern unsigned char data_02114e54[];

// USA: func_ov006_02158b78
ARM int CheckSomeFlag_02158b78(char* obj) {
	int flag = 0;
	if (func_02012444(&data_02114e30, 2) != 0) flag = 1;
	if (*(void**)(obj + 0x18) != NULL) {
		if (func_020e28dc() != 0) {
			if (func_020e2984(*(void**)(obj + 0x18)) != 0) flag = 1;
			return flag;
		}
	}
	{
		unsigned char* d = data_02114e54;
		if (d[0x55] != 0) {
			int varHi, varLo;
			func_02012a84(d, (short*)&varHi, (short*)&varLo);
			if (func_02080d54(*(void**)(obj + 0x14), *(short*)(obj + 0x36e), (short)varHi, (short)varLo) == 0) flag = 1;
		}
	}
	return flag;
}
