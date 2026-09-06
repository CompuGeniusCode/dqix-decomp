#include <globaldefs.h>

extern "C" int GetVal(int a, int b);
extern "C" void TakesChar(void* a, char b, void* c);

ARM void CallerX(void* base, void* buf) {
    int r = GetVal(1, 1);
    if (r < 0) return;
    TakesChar(base, r, buf);
}
