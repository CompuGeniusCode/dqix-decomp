#include <globaldefs.h>

struct A02164d14 { float f0, f4, f8, fc; };
extern struct A02164d14 data_ov001_02164d14;

struct B02165880 { float f0; char pad0[0xc]; float f10; char pad1[0x18]; float f2c, f30, f34; };
extern struct B02165880 data_ov001_02165880;

// USA: func_ov001_02164aec
ARM void func_ov001_02164aec(void) {
    float v34 = data_ov001_02164d14.f4 + (data_ov001_02164d14.f0 + (data_ov001_02164d14.f8 + data_ov001_02164d14.fc));
    data_ov001_02165880.f34 = v34;
    float v10 = data_ov001_02165880.f0 + data_ov001_02164d14.f8;
    float fc = data_ov001_02164d14.fc;
    data_ov001_02165880.f10 = v10;
    float v30 = v10 + fc;
    float f0 = data_ov001_02164d14.f0;
    data_ov001_02165880.f30 = v30;
    float v2c = v30 + f0;
    data_ov001_02165880.f2c = v2c;
}
