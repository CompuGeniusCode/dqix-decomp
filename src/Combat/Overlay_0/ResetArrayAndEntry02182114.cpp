#include <globaldefs.h>

struct Struct02047230 {
    unsigned char pad[0x84];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
};
extern "C" void func_0204719c(struct Struct02047230* obj);

struct Entry021820fc { unsigned char a; unsigned char b; short c; short d; };
void ClearEntry021820fc(struct Entry021820fc* obj);

// USA: func_ov000_02182114
ARM void ResetArrayAndEntry02182114(char* p) {
    int i;
    for (i = 0; i < 13; i++) {
        func_0204719c((struct Struct02047230*)(p + i * 0x88));
    }
    ClearEntry021820fc((struct Entry021820fc*)(p + 0x6e8));
}
