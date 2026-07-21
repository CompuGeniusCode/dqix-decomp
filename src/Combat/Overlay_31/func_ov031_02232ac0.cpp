#include <globaldefs.h>

struct StateStruct1d_02232ac0 { unsigned char pad[0x1d]; unsigned char field1d; };
struct DataCC0_02232ac0 { unsigned char field0; unsigned char pad[3]; StateStruct1d_02232ac0 *ptr4; };
extern DataCC0_02232ac0 data_ov031_02290cc0;
extern "C" int func_ov031_0223c054(int);
extern int TailCall_02222ddc(void);
char* GetOffset400_02235c70(void);
extern "C" void func_ov031_0223c078(int, int, int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02232b44(void);

// USA: func_ov031_02232ac0  (semantic: CheckField1dThenTailCall_02232ac0)
extern "C" ARM void func_ov031_02232ac0(void) {
	if (func_ov031_0223c054(1) != 0) return;

	if (data_ov031_02290cc0.ptr4->field1d == 1) {
		if (data_ov031_02290cc0.field0 == 3 ||
		    *(unsigned char*)(GetOffset400_02235c70() + 0xe7) != 0xff) {
			TailCall_02222ddc();
		}
	}

	func_ov031_0223c078(3, 1, 1, 8);
	func_ov031_0223c078(3, 0, 0x14, 8);
	SetField_022274c0_022274c0((int)func_ov031_02232b44);
}
