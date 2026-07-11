#include <globaldefs.h>

extern char data_021015a0;
extern "C" int func_020d472c(int);
void SetField0x48UnlessState9Or10(int);

// USA: func_0202db08
ARM void PollField0x40OrSetState_0202db08(unsigned short* obj) {
    int r;
    if (obj[1] != 0) {
        SetField0x48UnlessState9Or10(obj[1]);
        *(int*)(&data_021015a0 + 0x10) = 0xa;
        return;
    }
    r = func_020d472c(*(int*)(&data_021015a0 + 0x40));
    if (r == 0) {
        *(int*)(&data_021015a0 + 0x10) = 1;
        return;
    }
    SetField0x48UnlessState9Or10(r);
    *(int*)(&data_021015a0 + 0x10) = 0xa;
}
