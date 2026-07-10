#include <globaldefs.h>

int GetData02104304Field4();
extern "C" void func_020301c8(int a1, int a2);

struct Obj020dbf70 {
    char pad[0xc];
    volatile int word_c;
    int word_10;
};

// USA: func_020dbf70
ARM void ReleaseHandle020dbf70(struct Obj020dbf70* o) {
    if (o->word_c < 0) return;
    func_020301c8(GetData02104304Field4(), o->word_c);
    o->word_c = -1;
    o->word_10 = 0;
}
