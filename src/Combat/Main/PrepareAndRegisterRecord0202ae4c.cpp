#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_0200f374(void* buf, int n);
struct Container0202baf4;
struct Record0202baf4;
ARM void RegisterRecord0202baf4(struct Container0202baf4* obj, struct Record0202baf4* item);
ARM int CopyStringBounded020d2f28(char* dst, const char* src, int n);

extern char data_020ef7a0[];
extern struct Container0202baf4 data_020fefec;

struct Item0202ae4c {
    char pad_00[0x3c];
    unsigned short h3c;
    char pad_3e[0xc];
    unsigned char b4a;
    char pad_4b[0x5];
    char field50[0x14];
    unsigned char b64;
};

// USA: func_0202ae4c  (semantic: PrepareAndRegisterRecord0202ae4c)
extern "C" ARM void func_0202ae4c(struct Item0202ae4c* item) {
    char buf[0x18];
    func_0200f374(buf, 0x15);
    if (item->h3c != 0 && item->b4a == 0x24) {
        memcpy(buf, item->field50, item->b64);
    } else {
        CopyStringBounded020d2f28(buf, data_020ef7a0, 0x15);
    }
    RegisterRecord0202baf4(&data_020fefec, (struct Record0202baf4*)item);
}
