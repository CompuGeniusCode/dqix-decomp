#include <globaldefs.h>

extern "C" void* func_ov006_0215919c(void*);
extern "C" void* func_ov006_021591c4(void*);
extern "C" void* func_ov006_021591ec(void*);

// USA: func_ov006_02159274
ARM void GetCombatLookupValues_02159274(char* obj, unsigned char* out1, short* out2, unsigned char* out3) {
	*out1 = 0;
	*out2 = -1;
	*out3 = 0;
	if (*(short*)(obj + 0x364) >= 0) {
		int off = *(short*)(obj + 0x362) - 0x5b;
		char sc = (char)off;
		void* p1 = func_ov006_0215919c(obj);
		void* p2 = func_ov006_021591c4(obj);
		void* p3 = func_ov006_021591ec(obj);
		if (p1 != NULL && p2 != NULL && p3 != NULL) {
			int a = *(short*)(obj + 0x364) - 0x64;
			int b = *(unsigned char*)(obj + 0x388);
			unsigned short idx = a + (int)(((unsigned int)b << 0x13) >> 0x10);
			*out1 = sc;
			*out2 = ((short*)p1)[idx];
			*out3 = *((unsigned char*)p2 + idx);
		}
	}
}
