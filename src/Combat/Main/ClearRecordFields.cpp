#include <globaldefs.h>

struct Record0204acb0 {
    short h0;    // 0x0
    short h2;    // 0x2
    char b4;     // 0x4
    char b5;     // 0x5
    char pad[2]; // 0x6..0x7
    int w8;      // 0x8
    int wc;      // 0xc
};

// USA: func_0204acb0
ARM void ClearRecordFields(struct Record0204acb0* rec) {
    rec->h0 = 0;
    rec->h2 = 0;
    rec->b4 = 0;
    rec->b5 = 0;
    rec->w8 = 0;
    rec->wc = 0;
}
