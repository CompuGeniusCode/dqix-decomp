#include <globaldefs.h>

struct Obj02226a64 { unsigned char pad[0x63]; signed char state; signed char field64; };
extern Obj02226a64* data_ov031_02250c00;
extern signed char data_ov031_02248d3a[];

extern "C" void func_ov031_022269d8(void);
extern "C" void func_ov031_02236878(int v);

// USA: func_ov031_02226a64
extern "C" ARM void func_ov031_02226a64(int input) {
	signed char old = data_ov031_02250c00->state;
	signed char* row = data_ov031_02248d3a + old * 4;
	data_ov031_02250c00->state = row[input];
	Obj02226a64* obj = data_ov031_02250c00;
	signed char ns = obj->state;
	if (ns == 0xd) {
		if (input == 1 || input == 3) {
			obj->field64 = old;
			goto end;
		}
	}
	if (ns == -1) {
		signed char f64 = obj->field64;
		if (f64 == 1 || f64 == 0xa) obj->state = 0xa;
		else obj->state = 0xb;
		goto end;
	}
	if (ns == -2) {
		signed char f64 = obj->field64;
		if (f64 == 1 || f64 == 0xa) obj->state = 1;
		else obj->state = 2;
	}
end:
	func_ov031_022269d8();
	func_ov031_02236878(8);
}
