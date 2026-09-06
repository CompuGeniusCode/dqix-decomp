#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c*, int);

struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(StructA0205d5d0*, int, int, int, unsigned char);

struct Container020e0310;
int GetFieldByKey020e0434(Container020e0310*, int);

int AppendString02042058(char*, const char*);
int AppendXTag(char*, int);

extern "C" void __clear(void*, int);
extern "C" int func_020426bc(void*, void*, int);
extern "C" void func_02042764(void*, void*, int);
extern "C" int func_020420e8(void*, int);

// USA: func_ov023_021d9e60
ARM void BuildFieldTag_021d9e60(char* obj) {
	if (!(*(int*)(obj + 0xd9c) & 0x8000)) return;
	char* buf = *(char**)(obj + 0xf8);
	memset(buf, 0, 0x960);
	if (*(signed char*)(obj + 0xc58) == 8) {
		Elem_0205d81c* elem = FindElementByC40205d81c((Struct_0205d81c*)(obj + 0x2b4), 3);
		*(unsigned short*)((char*)elem + 0xb8) = 0x11;
		*(unsigned short*)((char*)elem + 0xba) = 0x10;
		char nameBuf[0x80];
		char outBuf[0x80];
		__clear(nameBuf, 0x80);
		__clear(outBuf, 0x80);
		int idx = *(unsigned char*)(obj + 0xda3);
		int* arr = *(int**)(obj + 0xdb0);
		int i = func_020426bc((void*)arr[idx], nameBuf, 0);
		for (; i < 8; i++) nameBuf[i] = *(unsigned char*)(obj + 0xdb4);
		func_02042764(nameBuf, outBuf, 0);
		int len = func_020420e8(outBuf, 0);
		AppendXTag(buf, (0x50 - len) >> 1);
		AppendString02042058(buf, outBuf);
	} else {
		int val = GetFieldByKey020e0434((Container020e0310*)(obj + 0xe0), 0x4274);
		AppendString02042058(buf, (const char*)val);
	}
	TryApplyElemFields0205d5d0((StructA0205d5d0*)(obj + 0x2b4), 3, (int)buf, 0, 0);
	*(int*)(obj + 0xd9c) &= ~0x8000;
}
