#include <globaldefs.h>

struct Struct_0205bf3c {
    char unk0[0x30];
    int f30;
    short f34;
    unsigned char b36;
    unsigned char b37;
    unsigned char b38;
};

// USA: func_0205bf3c
ARM void ResetState0205bf3c(struct Struct_0205bf3c* s) {
    s->f30 = 0;
    s->f34 = 0;
    s->b36 = 0;
    s->b37 = 0;
    s->b38 = 0;
}
