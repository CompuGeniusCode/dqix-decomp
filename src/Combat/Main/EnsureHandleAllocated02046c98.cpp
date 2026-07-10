#include <globaldefs.h>

int GetData02104304Field4();
int CallFunc0202fa38ZeroPad(int a, int b, int c);
extern int data_020f00cc;

struct Handle02046c98 {
    unsigned char pad[0xe8];
    int f_e8;   // 0xe8
    int f_ec;   // 0xec
};

// USA: func_02046c98
ARM void EnsureHandleAllocated02046c98(struct Handle02046c98* h) {
    if (h->f_e8 != 0) return;
    h->f_ec = CallFunc0202fa38ZeroPad(GetData02104304Field4(), (int)&data_020f00cc, 0);
}
