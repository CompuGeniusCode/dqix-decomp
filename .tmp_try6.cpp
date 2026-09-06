#include <globaldefs.h>

extern "C" void* func_ov006_0215919c(void*);
extern "C" void func_ov006_02155710(void*, int, int);
extern int data_ov006_02160030[9];

// USA: func_ov006_0215f740
ARM void DoCombatLookup_0215f740(char* obj) {
	void* arr = func_ov006_0215919c(obj);
	if (arr != NULL) {
		struct Tbl9_0215f740 { unsigned int w[9]; };
		Tbl9_0215f740 buf9;
		int a = *(short*)(obj + 0x364) - 0x64;
		int b = *(unsigned char*)(obj + 0x388);
		unsigned short idx = a + (int)(((unsigned int)b << 0x13) >> 0x10);
		buf9 = *(Tbl9_0215f740*)data_ov006_02160030;
		{
			int off = *(short*)(obj + 0x362) - 0x5b;
			int val1 = ((short*)arr)[idx];
			int byteVal;
			if (off < 0) off = 0;
			if (off > 8) off = 8;
			byteVal = (signed char)buf9.w[off];
			func_ov006_02155710(*(void**)(obj + 0x10), val1, byteVal);
		}
	}
}
