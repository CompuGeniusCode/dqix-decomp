#include <globaldefs.h>

extern int GetField40_02239be8(void);
extern "C" void func_ov031_0223a47c(void);

struct StructA90_0223b010 { unsigned char pad[0xa90]; unsigned char fieldA90; };
extern struct StructA90_0223b010* data_ov031_02290d20;

// USA: func_ov031_0223b010  (semantic: SetFieldA90IfField40Is1_0223b010)
extern "C" ARM int func_ov031_0223b010(void) {
	if (GetField40_02239be8() != 1) return 0;
	func_ov031_0223a47c();
	data_ov031_02290d20->fieldA90 = 1;
	return 1;
}
