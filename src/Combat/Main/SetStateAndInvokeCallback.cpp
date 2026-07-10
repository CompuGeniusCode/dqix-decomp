#include <globaldefs.h>

extern char data_021015a0;
void SetStateFromField0x2(unsigned short*);
extern "C" int func_020d503c(void*);

// USA: func_0202df10
ARM int SetStateAndInvokeCallback() {
    *(int*)(&data_021015a0 + 0x10) = 3;
    if (func_020d503c((void*)SetStateFromField0x2) != 2) {
        *(int*)(&data_021015a0 + 0x10) = 9;
        return 0;
    }
    *(short*)(&data_021015a0 + 0xe) = 0;
    return 1;
}
