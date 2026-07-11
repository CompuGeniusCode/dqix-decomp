#include <globaldefs.h>

struct Obj020dbf70;
void ReleaseHandle020dbf70(struct Obj020dbf70* o);
int GetData02104304Field4();
int CallFunc0202fa38ZeroPad(int a, int b, int c);

struct BattleTask020dbf18 {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
};

// USA: func_020dbf18
ARM int BeginTask020dbf18(struct BattleTask020dbf18* a, int b, int c, int d, int e) {
    int handle = GetData02104304Field4();
    ReleaseHandle020dbf70((struct Obj020dbf70*)a);
    a->f0 = c;
    a->f4 = d;
    a->f8 = e;
    a->fc = CallFunc0202fa38ZeroPad(handle, b, 0);
    a->f10 = 1;
    return 0;
}
