#include <globaldefs.h>
extern "C" int c1(void);
extern "C" void use4(int,int,int,int);
extern "C" int tA(void) {
    int a = c1();
    int b = c1();
    int c = c1();
    int d = c1();
    use4(a,b,c,d);
    use4(a,b,c,d);
    return 0;
}
