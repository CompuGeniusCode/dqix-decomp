#include <globaldefs.h>

ARM void SetField1e_0223521c(void);
extern "C" void func_ov031_022238cc(void);
extern "C" int FastIntModulus(int, int);
extern "C" void func_ov031_0222c3b4(void);
extern "C" void func_ov031_0222c660(void);
extern "C" int FastIntDivide(int numer, unsigned int denom);
extern "C" void func_ov031_022351f8(int a);
ARM void ClearField1e_02235204(void);
extern "C" void func_ov031_0222c8cc(void);
extern "C" void func_ov031_0223e2c0(int idx, void* obj);

struct Inner0222c71c {
	unsigned char pad0[0x38];
	int field38;
	unsigned char pad1[0x40 - 0x38 - 4];
	unsigned short field40;
	unsigned char pad2[0x53 - 0x42];
	unsigned char field53;
};
struct Struct0222c71c {
	unsigned char pad[2];
	unsigned short field2;
	Inner0222c71c* field4;
};
extern Struct0222c71c data_ov031_02290c8c;

// USA: func_ov031_0222c71c  (semantic: AdjustCounterAndDispatch_0222c71c)  (semantic: AdjustCounterAndDispatch_0222c71c)
extern "C" ARM void func_ov031_0222c71c(void* param0) {
	SetField1e_0223521c();
	func_ov031_022238cc();

	if (data_ov031_02290c8c.field2 > 4) {
		data_ov031_02290c8c.field2 = data_ov031_02290c8c.field2 - 4;
	} else {
		data_ov031_02290c8c.field2 = 0;
	}

	int rem = FastIntModulus(data_ov031_02290c8c.field2, 0x1c);
	if (rem == 0x18) {
		func_ov031_0222c3b4();
		return;
	}

	if (rem > 0x18) {
		data_ov031_02290c8c.field2 = data_ov031_02290c8c.field2 + (0x1c - rem);
		rem = 0;
	}

	func_ov031_0222c660();
	if (rem != 0) return;

	int mulVal = data_ov031_02290c8c.field2 * data_ov031_02290c8c.field4->field53;
	int divResult = FastIntDivide(mulVal, data_ov031_02290c8c.field4->field40);
	func_ov031_022351f8(divResult);
	ClearField1e_02235204();
	func_ov031_0222c8cc();
	data_ov031_02290c8c.field4->field38 = 0;
	func_ov031_0223e2c0(0, param0);
}
