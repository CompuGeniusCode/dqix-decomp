#include <globaldefs.h>

extern "C" void func_ov017_021c9954(int a, int b, int c, void* d);

struct Struct021c9cb0 {
    char pad[4];
    unsigned short h4;
    unsigned char b6;
};

// USA: func_ov017_021c9cb0
ARM void TailCallBuildArgs_021c9cb0(void* self, Struct021c9cb0* s) {
    func_ov017_021c9954(s->h4, 1, s->b6 != 0, self);
}
