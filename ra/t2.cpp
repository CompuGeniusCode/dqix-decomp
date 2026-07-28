#include <globaldefs.h>
extern "C" int c1(void);
extern "C" int c2(void);
extern "C" void use2(int, int);
extern "C" int tA(void) {
    int b = c2();
    int a = c1();
    use2(a, b);
    use2(a, b);
    return 0;
}
