#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern int IsField19ZeroOrNull_02222e54(void);
extern "C" void func_ov031_022238cc(void);
extern "C" int func_ov031_02223440(void);
extern "C" void func_ov031_0223cbbc(int, int);
extern void SetField1014_022274d0(int, int);
extern void SetField_022274c0_022274c0(int);
extern void SetField181c_0222750c(int, int);
extern void SetStoredByte1_02230ef0(unsigned char);

extern "C" void func_ov031_0223b710(int);

struct DataCC8_02233784 { char pad0; signed char field1; unsigned char field2; char pad3; int field4; };
extern DataCC8_02233784 data_ov031_02290cc8;

extern "C" void func_ov031_02232508(void);
extern void ResetAndInit_02232024(void);
extern "C" void func_ov031_0222aeb4(void);
extern "C" void func_ov031_02231bb0(void);
extern "C" void func_ov031_0222ea24(void);

// USA: func_ov031_02233784  (semantic: CheckAndDispatchByField1_02233784)
extern "C" ARM void func_ov031_02233784(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	if (IsField19ZeroOrNull_02222e54() == 0) return;

	func_ov031_022238cc();
	func_ov031_02223440();
	func_ov031_0223b710(data_ov031_02290cc8.field4);
	func_ov031_0223cbbc(1, 1);
	func_ov031_0223cbbc(0, 0x14);

	if (data_ov031_02290cc8.field2 == 0) {
		SetField1014_022274d0(2, 0);
		SetField_022274c0_022274c0((int)func_ov031_02232508);
		return;
	}
	switch (data_ov031_02290cc8.field1) {
	case 0:
		SetField1014_022274d0(2, 1);
		SetField_022274c0_022274c0((int)ResetAndInit_02232024);
		return;
	case 1:
		SetField1014_022274d0(2, 1);
		SetField_022274c0_022274c0((int)func_ov031_0222aeb4);
		return;
	case 2:
		SetField1014_022274d0(2, 1);
		SetField_022274c0_022274c0((int)func_ov031_02231bb0);
		return;
	case 3:
		SetField1014_022274d0(2, 0);
		SetField181c_0222750c(0, 0);
		SetStoredByte1_02230ef0(1);
		SetField_022274c0_022274c0((int)func_ov031_0222ea24);
		return;
	}
}
