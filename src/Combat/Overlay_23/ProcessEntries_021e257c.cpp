#include <globaldefs.h>

struct Elem20_021e257c {
	short key;
	unsigned char kind;
	unsigned char loNibble3 : 4;
	unsigned char hiNibble3 : 4;
	char pad4[4];
	short dx8;
	short dyA;
	void* ptrC;
	unsigned char lowNibble10 : 4;
	unsigned char bit4_10 : 1;
	unsigned char bit5_10 : 1;
	unsigned char bit6_10 : 1;
	unsigned char unused10 : 1;
	char pad11[3];
};

struct MainObj_021e257c {
	char pad0[4];
	void* state;
	char pad8[4];
	Elem20_021e257c* entries;
	char pad10[6];
	unsigned short entryCount;
	char pad18[0x48 - 0x18];
	short field48;
	short field4a;
};

struct Container_021e27f8;
ARM void* FindEntryContaining_021e27f8(struct Container_021e27f8* obj, int key);
ARM void DrawGrid2x2Cells_021e2030(int a, int paramB, int paramC, void* cursor);
extern "C" int func_ov023_021e2c38(void* obj, int val);
extern "C" void func_ov023_021e2b5c(void* obj, int key, short* out1, short* out2);
extern "C" void func_0204f914(void* a, int nibble, int y, int x, int compX, int compY);
extern "C" int func_020420e8(void* ptr, int flag);
extern "C" void func_0204f41c(void* a, int y, int x, void* ptrC, int loNibble, int hiNibble, short* pField8, short* pFieldA, int zero);
extern "C" void func_0204f7e8(void* a, int y, int x, void* ptrC, int loNibble, int hiNibble, short* pField8, short* pFieldA, int bit4, int lowNibble10, bool bool5, bool bool6);

// USA: func_ov023_021e257c  (semantic: ProcessEntries_021e257c)
extern "C" ARM void func_ov023_021e257c(struct MainObj_021e257c* obj) {
	if (obj->state == 0) return;
	unsigned short i;
	for (i = 0; i < obj->entryCount; i++) {
		Elem20_021e257c* elem = &obj->entries[i];
		void* found = FindEntryContaining_021e27f8((struct Container_021e27f8*)obj, elem->key);
		if (!found) continue;
		if (!func_ov023_021e2c38(obj, *(short*)found)) continue;
		short y, x;
		func_ov023_021e2b5c(obj, elem->key, &y, &x);

		short computed = obj->field48;
		int nibble = elem->loNibble3;
		void* state = obj->state;
		if (computed == 0) computed = (short)(nibble + 1);
		if (nibble == 0xc) {
			computed = obj->field4a;
			if (computed == 0) computed = 0x14;
		}
		*(short*)((char*)state + 0xb4) = (short)nibble;
		*(short*)((char*)state + 0xb6) = computed;

		switch (elem->kind) {
		case 0: {
			int compX = (short)(y + elem->dx8);
			int compY = (short)(x + elem->dyA);
			func_0204f914(obj->state, elem->hiNibble3, y, x, compX, compY);
			break;
		}
		case 1: {
			if (*((unsigned char*)found + 0x16) & 0x8) y -= func_020420e8(elem->ptrC, 0) >> 1;
			if (*((unsigned char*)found + 0x16) & 0x10) y -= func_020420e8(elem->ptrC, 0);
			func_0204f41c(obj->state, y, x, elem->ptrC, elem->loNibble3, elem->hiNibble3, &elem->dx8, &elem->dyA, 0);
			break;
		}
		case 2: {
			func_0204f7e8(obj->state, y, x, elem->ptrC, elem->loNibble3, elem->hiNibble3, &elem->dx8, &elem->dyA,
				elem->bit4_10, elem->lowNibble10, elem->bit5_10, elem->bit6_10);
			break;
		}
		case 3:
			DrawGrid2x2Cells_021e2030((int)obj->state, y, x, elem->ptrC);
			break;
		}
	}
}
