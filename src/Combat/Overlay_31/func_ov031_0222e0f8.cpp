#include <globaldefs.h>

typedef void (*Handler0222e0f8)(void*);
struct Table0222e0f8 { Handler0222e0f8 h[5]; };
extern Table0222e0f8 data_ov031_02248f0c;

extern "C" bool func_ov031_02237eb0(void);

struct StructX0222e0f8 {
	unsigned char pad[4];
	int* field4;
	unsigned char pad2[0x15 - 8];
	unsigned char field15;
};
extern StructX0222e0f8* data_ov031_02290c98;

void GetFields181c_02227520(int* a, int* b);
void SetField_022274c0_022274c0(int v);
extern "C" void func_ov031_0222d9a4(void);
extern "C" void func_ov031_0222dee0(void);

// USA: func_ov031_0222e0f8
#pragma optimize_for_size off
extern "C" ARM void func_ov031_0222e0f8(void) {
	Table0222e0f8 table = data_ov031_02248f0c;

	if (func_ov031_02237eb0()) return;

	StructX0222e0f8* ptr = data_ov031_02290c98;
	if (ptr->field15 == 0) {
		*ptr->field4 &= 0xc1fffcff;
		SetField_022274c0_022274c0((int)func_ov031_0222d9a4);
		return;
	}

	int idx;
	GetFields181c_02227520(&idx, NULL);
	ptr = data_ov031_02290c98;
	table.h[idx]((char*)ptr + 8);
	SetField_022274c0_022274c0((int)func_ov031_0222dee0);
}
