#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int func_ov017_021b8468(void* obj);
void* GetField6b0_021b8470(void* obj);
void SetCombatWorkFlags0x55f4(void* work, int mask);

struct LocalEvt021cf694 {
	unsigned char pad0[4];
	int field4;
	int field8;
	unsigned short fieldc;
};

// USA: func_ov017_021cf694
ARM void ApplyEventTag22Fields_021cf694(int unused0, LocalEvt021cf694* evt, int unused2, unsigned char* base) {
	void* table = *(void**)(base + 0x3000 + 0x718);
	void* a = func_ov017_021b8478(table);
	if (a == NULL) {
		return;
	}
	int b = func_ov017_021b8468(table);
	if (b == 0) {
		return;
	}
	if (GetField6b0_021b8470(table) == NULL) {
		return;
	}
	if (evt->fieldc != *(unsigned short*)((char*)a + 8)) {
		return;
	}
	int v1 = evt->field4;
	int v2 = evt->field8;
	unsigned char* buf = (unsigned char*)b + 0x6000;
	*(int*)(buf + 0xe3c) = v1;
	*(int*)(buf + 0xe40) = v2;
	SetCombatWorkFlags0x55f4((void*)b, 0x20000);
}
