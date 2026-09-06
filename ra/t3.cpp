#include <globaldefs.h>
extern "C" int c1(void);
extern "C" int c2(void);
extern "C" void use2(int, int);
extern "C" int tA(void) {
    int a = c1();
    int b = c2();
    use2(b, a);
    use2(b, a);
    return 0;
}
