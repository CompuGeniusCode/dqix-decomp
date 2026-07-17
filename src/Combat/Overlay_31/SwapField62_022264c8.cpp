#include <globaldefs.h>

struct Struct022264c8_holder { unsigned char pad[0x62]; signed char field62; };
struct Struct022264c8_base { Struct022264c8_holder* field0; };
extern Struct022264c8_base data_ov031_02250c00;

extern "C" void func_ov031_02226910(int, int);

// USA: func_ov031_022264c8
ARM void SwapField62_022264c8(int a0) {
    if (a0 == data_ov031_02250c00.field0->field62) return;
    func_ov031_02226910(a0, 1);
    func_ov031_02226910(data_ov031_02250c00.field0->field62, 0);
    data_ov031_02250c00.field0->field62 = (signed char)a0;
}
