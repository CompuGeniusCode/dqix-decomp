#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void SetFlag0x6cBit0(unsigned char* obj);
int TrySetMode02076ccc(void*, int);

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_ov017_021b86f8(void* a, int id, int mode, int flag);
extern "C" void func_02076a8c(void);
extern "C" void func_ov017_021c98f4(int id, int flag);
extern "C" void* func_ov017_021b8478(void* a);
extern "C" int func_ov017_021b8468(void* a);
extern "C" void func_ov000_02163778(void);
extern "C" void* func_ov017_021a7c8c(void* a);
extern "C" void func_ov017_021a7c1c(void* a);
extern "C" void func_020dc548(signed char c, char* outBuf, char* outCount);
extern "C" void func_ov017_021917f0(signed char c, int index);

struct CombatantStruct* FindCombatantByField16a_021a278c(void* unused, int val);

// USA: func_ov017_021c9954
ARM void ProcessCombatantEvent_021c9954(int id, int flag, int mode, int count) {
	(void)GetBattleStruct();
	char* base = (char*)func_ov017_0218b5b0();
	char* p718 = base + 0x3000;
	unsigned char* obj = *(unsigned char**)(p718 + 0x718);

	func_ov017_021b86f8(obj, id, 1, mode);

	struct CombatantStruct* c = FindCombatantByField16a_021a278c(base, id);
	if (c && mode == 0) {
		func_02076a8c();
		SetFlag0x6cBit0((unsigned char*)c);
	}

	func_ov017_021c98f4(id, 0);

	if (flag != 0) {
		char* e = (char*)func_ov017_021b8478(obj);
		int f = func_ov017_021b8468(obj);
		if (f != 0 && e != NULL) {
			if (*(unsigned short*)(e + 8) == id) {
				func_ov000_02163778();
			}
		}
	}

	char* p4400 = base + 0x4400;
	unsigned short v = *(unsigned short*)(p4400 + 0xae);
	char* addr = base + 0xae + 0x4400;
	if (v == id) {
		*(unsigned short*)(addr + 0) = 0;
		*(unsigned short*)(addr + 2) = 0;
	}

	if (c != NULL && mode != 0) {
		TrySetMode02076ccc(c, 1);
		((unsigned char*)c)[0x17d] &= ~0x80;
	}

	unsigned char* d = *(unsigned char**)(base + 0x3000 + 0xb98);
	if (d[2] != 0) {
		char* r = (char*)func_ov017_021a7c8c(d);
		if (*(unsigned short*)(r + 4) == id) {
			func_ov017_021a7c1c(d);
		}
	}

	if (count > -1) {
		if (obj[3] == 0) {
			char stackBuf[8];
			func_020dc548((signed char)count, &stackBuf[1], &stackBuf[0]);
			for (int i = 0; i < stackBuf[0]; i++) {
				func_ov017_021917f0(stackBuf[1 + i], i);
			}
		}
	}
}
