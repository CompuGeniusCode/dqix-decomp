#include <globaldefs.h>

void ZeroFields021537a0(int* obj);
extern int data_ov001_021658d8;
extern unsigned char data_ov001_021658b8[];

// USA: func_ov001_0215e27c
ARM int ZeroGlobalAndClearFlag8c_0215e27c(void) {
    ZeroFields021537a0(&data_ov001_021658d8);
    data_ov001_021658b8[0x8c] = 0;
    return 1;
}
