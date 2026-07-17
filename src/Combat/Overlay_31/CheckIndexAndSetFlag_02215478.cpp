#include <globaldefs.h>

char* GetFieldPtrByMask_022133f8(int tag);
int ClearAndRelease_022191e0(void *p);
extern "C" unsigned int NormalizeIndex_022135ac(unsigned int);
extern "C" int GetGlobalField1000_02219220(void);
extern "C" void func_ov031_02219080(void);

// USA: func_ov031_02215478
#pragma optimize_for_size off
ARM int CheckIndexAndSetFlag_02215478(void *obj) {
	char *p = GetFieldPtrByMask_022133f8(1);
	int v = ClearAndRelease_022191e0(p);
	if (v != 0) {
		unsigned int idx = NormalizeIndex_022135ac(*(unsigned char*)((char*)obj + 0xd0d));
		if (*(unsigned char*)(p + 0x15) == idx) {
			*(int*)(p + 0x10) = GetGlobalField1000_02219220();
		}
		func_ov031_02219080();
		if (v == 0xb) return 0xf;
		*(unsigned char*)((char*)obj + (*(unsigned char*)((char*)obj + 0xd13) << 2) + 0x444) = 1;
		return 0xb;
	}
	return 0xe;
}
