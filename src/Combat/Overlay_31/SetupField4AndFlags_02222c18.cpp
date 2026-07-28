#include <globaldefs.h>

int HwDivideRemainder(int a, int b);
int Divide32(int a, unsigned int b);
extern "C" void func_ov031_0223bdb0(int a0, int val, void* obj);

struct Entry02222c18 { unsigned int word0; unsigned short hword4; unsigned short pad6; };
struct Ctx02222c18 {
	unsigned char pad0[4];
	Entry02222c18* field4;
	unsigned char byte8;
	unsigned char byte9;
};
extern Ctx02222c18* data_ov031_02250ba4;
extern unsigned char data_ov031_02248910[];

// USA: func_ov031_02222c18  (semantic: SetupField4AndFlags_02222c18)
extern "C" ARM void func_ov031_02222c18(void) {
	data_ov031_02250ba4->byte9 = HwDivideRemainder(data_ov031_02250ba4->byte9 + 1, 0x28);
	int d = Divide32(data_ov031_02250ba4->byte9, 5);
	func_ov031_0223bdb0(0, d + 0x47, data_ov031_02250ba4->field4);

	data_ov031_02250ba4->field4->hword4 = (data_ov031_02250ba4->field4->hword4 & ~0xc00) | 0x400;

	unsigned char t = data_ov031_02248910[data_ov031_02250ba4->byte8];
	Entry02222c18* e = data_ov031_02250ba4->field4;
	e->word0 &= ~0xc00;
	e->hword4 = (e->hword4 & ~0xf000) | (t << 12);

	data_ov031_02250ba4->field4->word0 = (data_ov031_02250ba4->field4->word0 & 0xfe00ff00) | 0x8b | 0xe60000;
}
