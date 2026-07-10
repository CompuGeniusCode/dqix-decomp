#include <globaldefs.h>

struct Struct_0205bf3c;

extern "C" void func_0205d6e4(void* a, int count);
extern "C" void func_0205d904(void* a);
void ResetState0205bf3c(struct Struct_0205bf3c* s);

struct Entry_0205d6a0 {
    char pad0[0x98];
    int f98;
    int f9c;
    char pad1[0xb3 - 0xa0];
    unsigned char fb3;
};

// USA: func_0205d6a0
ARM void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag) {
    int count;
    if (a->f98 == 0 || a->f9c == 0) return;
    count = 1;
    if (flag) count = a->fb3;
    func_0205d6e4(a, count);
    ResetState0205bf3c((struct Struct_0205bf3c*)((char*)a + 0x54));
    func_0205d904(a);
}
