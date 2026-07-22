#include <globaldefs.h>

int VariadicForward020c7170(int a, int b, int c, ...);
extern "C" int func_ov031_0223dd60(unsigned short* dst, unsigned char* src, int maxLen);

struct ParamA020b1d70;
extern "C" void func_ov031_0223c8d4(ParamA020b1d70* a, int b, int c, int d, int e, unsigned short* counts, int idx);

extern unsigned char data_ov031_0224bb7c;

struct Level14_02230088 { char pad[0x14]; ParamA020b1d70* field14; };
struct Struct02290ca0_02230088 { char pad[8]; Level14_02230088* field8; };
extern Struct02290ca0_02230088 data_ov031_02290ca0;

struct QuadBytes02230088 { unsigned char byte0; unsigned char byte1; unsigned char byte2; unsigned char byte3; };

// USA: func_ov031_02230088
extern "C" ARM void FormatQuadAndDispatchLabel_02230088(QuadBytes02230088* quad, int idx) {
    unsigned short wbuf[0x10];
    unsigned char buf[0x10];
    VariadicForward020c7170((int)buf, 0x10, (int)&data_ov031_0224bb7c, quad->byte0, quad->byte1, quad->byte2, quad->byte3);
    func_ov031_0223dd60(wbuf, buf, 0x10);
    func_ov031_0223c8d4(data_ov031_02290ca0.field8->field14, 0x5f, idx * 0x1d + 8, 2, 7, wbuf, 1);
}
