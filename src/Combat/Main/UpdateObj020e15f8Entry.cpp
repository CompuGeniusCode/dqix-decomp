#include <globaldefs.h>

struct FourShorts020e12a8;
void StoreFourShorts(struct FourShorts020e12a8* dst, short a, short b, short c, short d);

extern "C" int func_020420e8(int, unsigned char);
extern "C" int func_0205b234(void*, short, short, int, unsigned char, unsigned char);

// USA: func_020e2310
ARM void UpdateObj020e15f8Entry(char* obj, int idx, int a2, int a3, int a4, unsigned char a5, unsigned char a6)
{
    if (idx >= 0 && idx < 3) {
        int ret = func_020420e8(a4, a6);
        StoreFourShorts((struct FourShorts020e12a8*)(obj + 0xa + idx * 8), a2, a3, a2 + ret, a3 + 0xc);
    }
    if ((signed char)obj[8] <= idx) {
        obj[8] = idx + 1;
    }
    void **p = *(void***)(obj + 4);
    func_0205b234(p[1], a2, a3, a4, a5, a6);
}
