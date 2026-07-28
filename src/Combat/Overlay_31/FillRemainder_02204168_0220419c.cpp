#include <globaldefs.h>

extern "C" unsigned char* func_ov031_02203fdc(void* buf, int n, int* out);
ARM void* FillRemainder_02204168(int value, unsigned int end, void* dst, unsigned int start);
extern "C" int func_ov031_02203a84(int param0, int param1);

extern unsigned char data_ov031_0224ced6[];

struct StateBlock0224c980_0220419c {
    unsigned char pad1[0x34];
    unsigned int field34;
};
extern StateBlock0224c980_0220419c data_ov031_0224c980;

// USA: func_ov031_0220419c
extern "C" ARM int func_ov031_0220419c(void) {
    int outVal;
    unsigned char* buf = data_ov031_0224ced6;
    unsigned char* ip = func_ov031_02203fdc(buf, 1, &outVal);
    if (data_ov031_0224c980.field34 != 0) {
        ip[0] = 0x32;
        ip[1] = 4;
        ip[2] = (unsigned char)((unsigned short)(data_ov031_0224c980.field34 >> 16) >> 8);
        ip[3] = (unsigned char)(data_ov031_0224c980.field34 >> 16);
        ip[4] = (unsigned char)((unsigned short)data_ov031_0224c980.field34 >> 8);
        ip[5] = (unsigned char)data_ov031_0224c980.field34;
        ip += 6;
    }
    ip[0] = 0xff;
    unsigned char* dst = (unsigned char*)FillRemainder_02204168(0, 0x12c, ip + 1, (unsigned int)((ip + 1) - buf));
    func_ov031_02203a84((int)buf, (int)(dst - buf));
    return outVal;
}
