#include <globaldefs.h>

extern unsigned char data_ov031_02248e2c;
struct Struct0222cb5c { unsigned char pad[4]; char* field4; };
extern Struct0222cb5c data_ov031_02290c8c;
extern "C" int func_ov031_02234ff8(int, int, int);

// USA: func_ov031_0222cb5c
ARM void ForwardByteAndPtr8_0222cb5c(void) {
    unsigned char v = data_ov031_02248e2c;
    volatile unsigned char tmp = v;
    int arg0 = *(int*)(data_ov031_02290c8c.field4 + 8);
    func_ov031_02234ff8(arg0, v, v);
}
