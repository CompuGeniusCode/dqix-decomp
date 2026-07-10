#include <globaldefs.h>

extern "C" void func_020d0050(int value);

struct Flag02108dfc {
    unsigned char flag;
    unsigned char pad1;
    unsigned short value;
};

extern struct Flag02108dfc data_02108dfc;

// USA: func_02075cb8
ARM void NotifyU16AndSetFlag02075cb8(void) {
    func_020d0050(data_02108dfc.value);
    data_02108dfc.flag = 1;
}
