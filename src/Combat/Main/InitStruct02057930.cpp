#include <globaldefs.h>

void InitStruct02059cc8(unsigned char* obj);

struct Foo02057930 {
    int f0;                       // 0x0
    int f4;                       // 0x4
    unsigned char arr[16][0xd4];  // 0x8 .. 0xd48
    int fd48;                     // 0xd48
    int fd4c;                     // 0xd4c
    int fd50;                     // 0xd50
};

// USA: func_02057930
ARM void InitStruct02057930(Foo02057930* p) {
    int i;
    p->f0 = 0;
    p->f4 = 0;
    p->fd4c = 0;
    p->fd50 = 0;
    for (i = 0; i < 16; i++) {
        InitStruct02059cc8(p->arr[i]);
    }
    p->fd48 = 0;
}
