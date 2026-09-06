#include <globaldefs.h>
struct EntityStruct022264c8 { unsigned char pad[0x62]; signed char field62; };
extern EntityStruct022264c8* data_ov031_02250c00;
extern "C" void func_ov031_02226910(int a0, int a1);

// USA: func_ov031_022264c8  (semantic: SetField62IfChanged_022264c8)
extern "C" ARM void func_ov031_022264c8(int id) {
	if (id == data_ov031_02250c00->field62) return;
	func_ov031_02226910(id, 1);
	func_ov031_02226910(data_ov031_02250c00->field62, 0);
	data_ov031_02250c00->field62 = id;
}
