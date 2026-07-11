#include <globaldefs.h>

extern char data_02111818;
extern "C" int func_020cf08c(int a, void (*cb)(int), int c);
extern "C" void func_020cf864(void);
void StoreValueAt0x2c(int val);

// USA: func_020cf0fc
ARM int RegisterSlotA020cf0fc(int a) {
    int result = func_020cf08c(a, StoreValueAt0x2c, 0);
    *(int*)(&data_02111818 + 0x2c) = result;
    if (result == 0) {
        func_020cf864();
    }
    return *(int*)(&data_02111818 + 0x2c);
}
