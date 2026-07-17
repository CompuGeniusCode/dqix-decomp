#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" struct BattleStruct* GetBattleStruct();
int GetGlobalField0x1c020421a0(void);
extern "C" void func_02046380(void* global);
extern "C" struct Container020dedd0* func_ov004_02156fd4(void* obj, int key);
struct Elem02158a60 { char pad[0x18]; short field18; };
Elem02158a60* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
void* CallFunc020e52a0(void* arr, int key);
extern "C" void func_ov011_021848a0(void* obj, int val);

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);
int CheckField0NonZero(int* obj);

struct BF02158a60 { unsigned short low13 : 13; unsigned short hi3 : 3; };

struct Struct021707d8_02158a60 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_02158a60 data_ov004_021707d8;

// USA: func_ov004_02158a60
ARM int CheckWeatherStateAndNotify_02158a60(void* a) {
	struct BattleStruct* bs = GetBattleStruct();
	char* r6 = (char*)bs + 0x26c + 0x5c00;

	short f1 = *(short*)(r6 + 0xf8);
	if (f1 <= 0) {
		unsigned short f2 = *(unsigned short*)(r6 + 0xfa);
		if (f2 == 0) {
			void* s = func_0202ae18();
			if (func_0202c540(s)) {
				func_ov011_021848a0(a, 0x3ae);
				return 0;
			}
			if (CheckField0NonZero((int*)s)) {
				func_ov011_021848a0(a, 0x24cd);
				return 0;
			}
			int bits = ((struct BF02158a60*)(r6 + 0x100 + 0xc))->low13;
			if (bits & 0x10) {
				func_ov011_021848a0(a, 0x3a6);
				return 0;
			}
			func_ov011_021848a0(a, 0x3b0);
			return 0;
		}
	}

	int g = GetGlobalField0x1c020421a0();
	func_02046380((void*)g);

	struct Container020dedd0* c = func_ov004_02156fd4(a, 5);
	Elem02158a60* elem = FindElementByKey020dedd0(c, f1);
	void* v = CallFunc020e52a0(data_ov004_021707d8.ptr + 0x8c, elem->field18);
	*(void**)((char*)g + 0x18) = v;

	func_ov011_021848a0(a, 0x3a3);
	return 0;
}
