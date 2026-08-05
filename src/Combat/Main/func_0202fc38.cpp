#include <globaldefs.h>

extern "C" void func_020d970c(void);
extern "C" void func_020c9be0(void);
extern "C" void func_020d974c(void);

extern unsigned short data_02104304;

struct Entry0202fc38 {
    char pad0[0x30];
    unsigned short field30;
    signed char lowNibble : 4;
    signed char highNibble : 4;
    char pad33[9];
    int field3c;
    char padEnd[4];
};

// USA: func_0202fc38
extern "C" ARM int func_0202fc38(unsigned char* obj, int arg1, int arg2) {
    int result = -1;
    func_020d970c();
    if (*(volatile int*)(obj + 0x124) >= 0x18) {
        func_020c9be0();
    } else {
        struct Entry0202fc38* entry = &((struct Entry0202fc38*)(obj + 0x128))[*(volatile int*)(obj + 0x124)];
        entry->field30 = data_02104304;
        entry->lowNibble = 0;
        entry->field3c = arg1;
        entry->highNibble = (arg2 != 0) ? 3 : 4;
        result = data_02104304;
        *(volatile int*)(obj + 0x124) = *(volatile int*)(obj + 0x124) + 1;
        data_02104304 = (result + 1) & 0x3ff;
        *(volatile int*)(obj + 0x78c) &= ~1;
    }
    func_020d974c();
    return result;
}
