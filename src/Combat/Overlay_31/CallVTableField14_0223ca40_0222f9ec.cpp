#include <globaldefs.h>

struct Field8Struct0222f9ec {
	char pad[8];
	void* nestedField8;
	char pad2[0x14 - 0xc];
	void* field14;
};

struct Obj0222f9ec {
	char pad0[4];
	unsigned short field4;
	char pad1[2];
	Field8Struct0222f9ec* field8;
};

int Divide32(int numer, unsigned int denom);
extern "C" ARM asm void CallVTableField14_0223ca40(void* obj, int unused);
extern "C" void func_ov031_0222faac(int a, int b);
extern "C" ARM void func_ov031_02234f4c(void* a, int offset, int c, int count);
extern "C" void func_ov031_0222fc48(int a, int b);
ARM void SetField604_02234f34(void);
void SetFlagIfMatchesElem0_0223caec(void* ptr);
extern "C" void func_ov031_02230120(void);
extern Obj0222f9ec data_ov031_02290ca0;
extern unsigned short data_ov031_02248f96[];

// USA: func_ov031_0222f9ec  (semantic: InitDivideEntriesAndFinalize_0222f9ec)
extern "C" ARM void func_ov031_0222f9ec(void) {
	int div = Divide32(data_ov031_02290ca0.field4, 0x1d);
	CallVTableField14_0223ca40(data_ov031_02290ca0.field8->field14, 0);

	int idx = div;
	int i = 0;
	do {
		func_ov031_0222faac(idx, i);
		i++;
		idx++;
	} while (i < 5);

	func_ov031_02234f4c(
		(char*)data_ov031_02290ca0.field8->nestedField8 + data_ov031_02248f96[div] * 2,
		0, 0x1e, 0x13);

	int j = 0;
	do {
		func_ov031_0222fc48(div, j);
		j++;
		div++;
	} while (j < 5);

	SetField604_02234f34();
	SetFlagIfMatchesElem0_0223caec(data_ov031_02290ca0.field8->field14);
	func_ov031_02230120();
}
