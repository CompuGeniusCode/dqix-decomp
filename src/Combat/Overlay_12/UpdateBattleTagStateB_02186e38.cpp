#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* _Z15GetBattleStructv();

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);

void SetupBattleTag02189a78(char* base);

struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);

struct Obj0205eaa0;
extern struct Obj0205eaa0 data_02108760;
extern "C" int _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);

struct Obj021e6e20;
int TestFlagsAndActiveElement2_021e6e20(struct Obj021e6e20* obj);

extern "C" void func_ov023_021e6e60(void* self);
extern "C" int func_ov023_021e6de4(char* obj);
extern "C" int func_ov012_0218432c(int a);
extern "C" int func_ov023_021e6448(void* self);
extern "C" void func_ov012_0218adac(void* self, int a, int b, int c);
extern "C" void func_ov012_0218930c(void* self, int flag);

// USA: func_ov012_02186e38  (semantic: UpdateBattleTagStateB_02186e38)
extern "C" ARM void func_ov012_02186e38(char* self) {
	unsigned char state = *(unsigned char*)(self + 0x1370);
	if (state == 0) {
		*(unsigned char*)(self + 0x13a0) = 0;
		int v = func_ov012_0218432c(0);
		*(int*)(self + 0x13dc) = v;
		if (v < 0) *(int*)(self + 0x13dc) = 0;

		FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(self + 0xac), 0, 3);
		func_ov023_021e6e60(self);
		SetupBattleTag02189a78(self);
		(*(unsigned char*)(self + 0x1370))++;
		return;
	}
	if (state != 1) return;

	*(unsigned char*)(self + 0x13a0) = 1;
	*(int*)(self + 0x13dc) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(self + 0xac));
	if (func_ov023_021e6448(self) != 0) {
		*(int*)(self + 0x13dc) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(self + 0xac));
	}

	if (func_ov023_021e6de4(self) != 0) {
		_Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
		void* battleStruct = _Z15GetBattleStructv();
		int val = *(int*)(self + 0x13dc);
		void* name = FindEntryByKey((struct TableA68*)(self + 0x133c), (short)(val + 0x2846));
		struct Field569c { char pad[4]; unsigned int field4; };
		struct Field569c* addr = (struct Field569c*)((char*)battleStruct + 0x29c + 0x5400);

		memset(self + 0x1440, 0, 0x40);
		int len = strlen((char*)name);
		memcpy(self + 0x1440, name, len);

		unsigned int val2 = *(unsigned int*)(self + 0x13dc);
		unsigned int packed = (val2 + 0x136) << 0x16;
		addr->field4 = (addr->field4 & 0xfff801ff) | (packed >> 0xd);

		func_ov012_0218adac(self, 0, -1, 0);
		func_ov012_0218930c(self, 0);
		return;
	}

	if (TestFlagsAndActiveElement2_021e6e20((struct Obj021e6e20*)self) == 0) return;
	func_ov012_0218930c(self, 1);
}
