#include <globaldefs.h>
void PrepareAndCommit020d0050(int);


struct Flag02108dfc {
    unsigned char flag;
    unsigned char pad1;
    unsigned short value;
};

extern struct Flag02108dfc data_02108dfc;

// USA: func_02075cb8
ARM void NotifyU16AndSetFlag02075cb8(void) {
    PrepareAndCommit020d0050((int)(data_02108dfc.value));
    data_02108dfc.flag = 1;
}
