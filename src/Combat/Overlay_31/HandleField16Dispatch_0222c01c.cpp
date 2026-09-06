#include <globaldefs.h>

int GetField16_02222e0c(void);
extern "C" void func_ov031_02236878(int a);
void ForwardByteAndPtr8_0222cb5c(void);
extern "C" int FastIntDivide(int numer, unsigned int denom);
void SetField1e_0223521c(void);
void SetField18_02222e98(void);
extern "C" void func_ov031_02237b2c(int a, int b, int c, int d, int e);
void SetField_022274c0_022274c0(int fn);
void AdvanceUnlessField1bActive_0222cb8c(void);
extern "C" void func_ov031_0222c128(void);

struct Manager0222c01c {
	char* entries;
	char pad4[0x38 - 4];
	int field38;
	char pad3c[0x52 - 0x3c];
	unsigned char field52;
	unsigned char pad53;
	unsigned char field54;
	char pad55[0x57 - 0x55];
	unsigned char field57;
};

struct Ctx02290c8c {
	unsigned char field0;
	unsigned char pad1;
	unsigned short field2;
	Manager0222c01c* field4;
};

extern Ctx02290c8c data_ov031_02290c8c;

// USA: func_ov031_0222c01c  (semantic: HandleField16Dispatch_0222c01c)
extern "C" ARM void func_ov031_0222c01c(void) {
	if (data_ov031_02290c8c.field4->field38 != 0 || data_ov031_02290c8c.field4->field57 != 0) return;

	int r = GetField16_02222e0c();
	switch (r) {
	case 0:
		func_ov031_02236878(7);
		break;
	case 1:
		if (data_ov031_02290c8c.field0 == 4) {
			data_ov031_02290c8c.field4->field54 = 1;
			func_ov031_02236878(6);
			ForwardByteAndPtr8_0222cb5c();
			break;
		}
		{
			int d = FastIntDivide(data_ov031_02290c8c.field2, 0x1c);
			int idx = data_ov031_02290c8c.field0 + d;
			Manager0222c01c* mgr = data_ov031_02290c8c.field4;
			unsigned char* entry = (unsigned char*)(mgr->entries + idx * 0x2a);
			if (entry[0x28] == 2) {
				func_ov031_02236878(9);
				SetField1e_0223521c();
				SetField18_02222e98();
				func_ov031_02237b2c(0xe, 1, 1, -1, 0);
				SetField_022274c0_022274c0((int)AdvanceUnlessField1bActive_0222cb8c);
				return;
			}
			mgr->field54 = 1;
			data_ov031_02290c8c.field4->field52 = (unsigned char)idx;
			func_ov031_02236878(6);
		}
		break;
	default:
		return;
	}
	SetField_022274c0_022274c0((int)func_ov031_0222c128);
}
