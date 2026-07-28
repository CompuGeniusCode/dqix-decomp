#include <globaldefs.h>

extern unsigned short GetGlobal02290d14_0223911c(void);
extern int GetField40_02239be8(void);
extern "C" int func_ov031_0223a47c(void);
extern "C" int func_ov031_02239130(int a);
void DispatchOrRetryLoad_022387f4(int a0, int a1);
extern "C" int func_ov031_02238c40(void);
extern "C" void func_ov031_02238ca8(void);
void CallSetGlobalThenOv027_02238da0(void);

struct Struct0223ac38 {
	unsigned char pad0[0x64a];
	unsigned short field64a;
	unsigned char pad1[0x444];
	unsigned char fieldA90;
	unsigned char pad2[7];
	int fieldA98;
};
extern struct Struct0223ac38* data_ov031_02290d20;

// USA: func_ov031_0223ac38  (semantic: DispatchLoadState_0223ac38)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_0223ac38(void) {
	switch (GetGlobal02290d14_0223911c()) {
	case 1: {
		unsigned short v = *(unsigned short*)((char*)data_ov031_02290d20 + 0x600 + 0x4a);
		DispatchOrRetryLoad_022387f4((int)((char*)data_ov031_02290d20 + 0x2b4 + 0x800), v);
		break;
	}
	case 2:
		if (func_ov031_02239130(2) != 0) {
			data_ov031_02290d20->fieldA90 = 5;
			break;
		}
		if (func_ov031_02239130(3) != 0 || func_ov031_02239130(4) != 0) {
			data_ov031_02290d20->fieldA90 = 6;
			break;
		}
		if (data_ov031_02290d20->fieldA90 == 5 && func_ov031_02239130(2) == 0) {
			data_ov031_02290d20->fieldA90 = 0xd;
		}
		break;
	case 3:
		if (func_ov031_02238c40() != 0) {
			func_ov031_02238ca8();
			break;
		}
		{
			unsigned char v = (unsigned char)(data_ov031_02290d20->fieldA90 + 0xfa);
			if (v > 1) break;
		}
		if (func_ov031_02239130(3) != 0) break;
		data_ov031_02290d20->fieldA90 = 0x12;
		break;
	case 5:
		data_ov031_02290d20->fieldA90 = 7;
		break;
	case 7:
		CallSetGlobalThenOv027_02238da0();
		data_ov031_02290d20->fieldA90 = 1;
		break;
	case 4:
	case 6:
		break;
	case 0:
		switch (GetField40_02239be8()) {
		case 1:
			func_ov031_0223a47c();
			break;
		case 0:
			data_ov031_02290d20->fieldA90 = 0x1f;
			break;
		case 3:
			break;
		default:
			data_ov031_02290d20->fieldA90 = 0x1f;
			break;
		}
		break;
	}
}
