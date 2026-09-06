#include <globaldefs.h>

ARM int GetData02104304Field4();
extern "C" void func_020301c8(int);
extern "C" void func_ov023_021dd4cc(void*, int);

static void ResetIfActive_02155710(char* obj, int offCond, int offSet, int val) {
	if (*(int*)(obj + offCond) >= 0) {
		func_020301c8(val);
		*(int*)(obj + offSet) = -1;
	}
}

// USA: func_ov006_02155710
ARM void SetCombatEntry_02155710(char* obj, short arg1, char arg2) {
	int val = GetData02104304Field4();
	ResetIfActive_02155710(obj, 0xad4, 0xad4, val);
	*(int*)(obj + 0xad4) = -1;
	*(char*)(obj + 0xade) = 0;

	{
		unsigned short flags = *(unsigned short*)(obj + 0xae2);
		flags |= 2;
		*(unsigned short*)(obj + 0xae2) = flags;
		func_ov023_021dd4cc(obj + 0xae4, 2);
	}
	*(short*)(obj + 0x12b8) = arg1;
	*(char*)(obj + 0x12ba) = arg2;
	{
		unsigned short flags = *(unsigned short*)(obj + 0xae2);
		flags &= ~1;
		*(unsigned short*)(obj + 0xae2) = flags;
	}

	ResetIfActive_02155710(obj, 0xad8, 0xad8, val);
	*(int*)(obj + 0xad8) = -1;
	*(char*)(obj + 0xadf) = 0;
}
