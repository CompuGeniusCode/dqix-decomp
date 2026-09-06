#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* _Z15GetBattleStructv();
extern "C" void* _Z10GetWord0x0Pi(void* battle);
extern "C" void* _Z17GetGlobal02109400v();

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);

struct Obj0205eaa0;
extern struct Obj0205eaa0 data_02108760;
extern "C" int _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);

struct Entry_0205d6a0;
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0* a, int flag);

struct Obj021e6e20;
int TestFlagsAndActiveElement2_021e6e20(struct Obj021e6e20* obj);

extern "C" void func_ov023_021e6e60(void* self);
extern "C" int func_ov023_021e6de4(char* obj);
extern "C" void func_ov012_0218943c(void* self);

// USA: func_ov012_02186a7c  (semantic: UpdateBattleTagStateA_02186a7c)
extern "C" ARM void func_ov012_02186a7c(char* self) {
	_Z10GetWord0x0Pi(_Z15GetBattleStructv());
	(int)BackgroundLoader::GetInstance();
	_Z17GetGlobal02109400v();

	unsigned char state = *(unsigned char*)(self + 0x1370);
	if (state == 0) {
		*(unsigned char*)(self + 0x13a0) = 0;
		*(int*)(self + 0x13d4) = 0;
		FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(self + 0xac), 0, 2);
		func_ov023_021e6e60(self);
		func_ov012_0218943c(self);
		(*(unsigned char*)(self + 0x1370))++;
		return;
	}
	if (state != 1) return;

	*(unsigned char*)(self + 0x13a0) = 1;
	*(int*)(self + 0x13d4) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(self + 0xac));

	int flag = 0;
	if (func_ov023_021e6de4(self) != 0) {
		*(unsigned char*)(self + 0x164) = *(unsigned char*)(self + 0x1371);
		*(unsigned char*)(self + 0x13a0) = 0;
		_Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);

		unsigned char* p = (unsigned char*)(self + 0x1000);
		int v = *(int*)(p + 0x3d4);
		switch (v) {
		case 0: p[0x371] = 2; p[0x370] = flag; break;
		case 1: p[0x371] = 9; p[0x370] = flag; break;
		case 2: p[0x371] = 0xa; p[0x370] = flag; break;
		case 3: p[0x371] = 0xd; p[0x370] = flag; break;
		case 4: p[0x371] = 0xe; p[0x370] = flag; break;
		case 5: flag = 1; break;
		}
	} else {
		if (TestFlagsAndActiveElement2_021e6e20((struct Obj021e6e20*)self) != 0) flag = 1;
	}

	if (flag == 0) return;
	*(unsigned char*)(self + 0x13a0) = 0;
	*(int*)(self + 0x13d4) = 0;
	_Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)(self + 0xac), 1);
	*(unsigned char*)(self + 0x1371) = 0xf;
	*(unsigned char*)(self + 0x1370) = 0;
}
