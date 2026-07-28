#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetField0x3f8Address(struct BattleStruct* battleStruct);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void* func_0205ec34(void);
int TestBitInByteArray(int a, unsigned char* b, int c);
extern "C" int func_0202c540(void* p);
extern "C" void func_020103c8(int val, int arg);
struct Data02107930;
Data02107930* GetData02107930(void);

struct Evt021c51c0 {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char field5;
	unsigned short field6;
	unsigned short field8;
	int fieldc;
	unsigned short field10;
	unsigned short field12;
};

// USA: func_ov017_021c51c0  (semantic: ApplyEvt021c51c0)
extern "C" ARM void func_ov017_021c51c0(int flag, Evt021c51c0* evt, struct BattleStruct* battleStruct, unsigned char* obj, struct SearchStruct0202c1a4* search) {
	unsigned char* base = obj + 0x3000;
	void* h = *(void**)(base + 0x70c);
	void* ctx = GetField0x3f8Address(battleStruct);
	signed char cur = GetSearchStructCurrentArrEntry(search);
	if (evt->field4 != cur) return;

	*(unsigned char*)((char*)h + 0xb) = 1;

	if (evt->field5 == 1) {
		void* work = func_0205ec34();
		if (TestBitInByteArray((int)work, (unsigned char*)work + 0x8c, evt->field8 + 0x38e) == 0) {
			*(int*)((char*)ctx + 0x24) = evt->field6;
		}
	} else if (evt->field5 == 2) {
		*(int*)((char*)ctx + 0x28) = evt->field6;
		*(int*)((char*)ctx + 0x2c) = evt->field8;
	}

	if (func_0202c540(search) != 0 && flag == 0) {
		func_020103c8((int)battleStruct, evt->fieldc);
		GetData02107930();
	}

	*(unsigned short*)((char*)h + 0xe) = evt->field10;
	*(unsigned short*)((char*)h + 0x10) = evt->field12;
}
