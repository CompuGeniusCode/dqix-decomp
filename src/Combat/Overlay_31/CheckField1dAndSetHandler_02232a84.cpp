#include <globaldefs.h>

struct StateStruct1d_02232a84 { unsigned char pad[0x1d]; unsigned char field1d; };
struct DataCC0_02232a84 { unsigned char field0; unsigned char pad[3]; StateStruct1d_02232a84 *ptr4; };
extern DataCC0_02232a84 data_ov031_02290cc0;
extern "C" void func_ov031_02236e60(void);
extern void SetField18_02222e98(void);
extern "C" void func_ov031_0223c278(int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02232ac0(void);

// USA: func_ov031_02232a84  (semantic: CheckField1dAndSetHandler_02232a84)
extern "C" ARM void func_ov031_02232a84(void) {
	if (data_ov031_02290cc0.ptr4->field1d == 2) {
		func_ov031_02236e60();
	}
	SetField18_02222e98();
	func_ov031_0223c278(8);
	SetField_022274c0_022274c0((int)func_ov031_02232ac0);
}
