#include <globaldefs.h>

int GetData02104304Field4();
int GetSignBit0At0x78c(unsigned char* p);
extern "C" int func_ov025_021eb0f4(int a);
extern int data_ov025_021ef988;

// USA: func_ov025_021e413c  (semantic: Func_021e413c)
extern "C" ARM int func_ov025_021e413c(void) {
    if (GetSignBit0At0x78c((unsigned char*)GetData02104304Field4()) == 0) {
        return 0;
    }
    return func_ov025_021eb0f4(*(int*)((char*)&data_ov025_021ef988 + 0xc));
}
