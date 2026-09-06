#include <globaldefs.h>
extern unsigned char g;
extern short arr;
extern "C" ARM void test5(void) {
    unsigned char i = 0;
    do {
        int idx = i * 8;
        unsigned short a = *(unsigned short*)((char*)&arr + idx);
        g = i;
        (void)a;
        i++;
    } while (i < 2);
}
