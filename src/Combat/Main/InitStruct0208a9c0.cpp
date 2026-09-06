#include <globaldefs.h>

struct InitStruct0208a9c0Data {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char arr7[4];
    unsigned char padb;
    int words[3];
    unsigned char arr18[4];
};

// USA: func_0208a9c0
ARM void InitStruct0208a9c0(struct InitStruct0208a9c0Data* p, unsigned char a, unsigned char b, unsigned char c) {
    int i;
    int j;
    p->b4 = a;
    p->b5 = b;
    p->b6 = c;
    for (i = 0; i < 4; i++) {
        p->arr7[i] = 0xfe;
        p->arr18[i] = 0;
    }
    for (j = 0; j < 3; j++) {
        p->words[j] = 0;
    }
}
