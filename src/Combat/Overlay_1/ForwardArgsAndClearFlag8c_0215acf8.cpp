#include <globaldefs.h>

struct DataB8_acf8 { int field0; char pad[0x8c - 4]; unsigned char flag8c; };
extern DataB8_acf8 data_ov001_021658b8;
extern int data_ov001_021658d8;
extern "C" void func_ov001_021537b0(void* a, int b, int c, int d);

// USA: func_ov001_0215acf8
ARM void ForwardArgsAndClearFlag8c_0215acf8(int a, int b) {
    func_ov001_021537b0(&data_ov001_021658d8, data_ov001_021658b8.field0, a, b);
    data_ov001_021658b8.flag8c = 0;
}
