#include <globaldefs.h>

struct Substruct02042c3c {
    char unk[0x4];
    unsigned short width;
    unsigned short height;
};

struct Holder02042c3c {
    char unk[0x440];
    struct Substruct02042c3c* substruct;
};

// USA: func_02042c3c
ARM void SetSubstructSize02042c3c(struct Holder02042c3c* holder, int width, int height) {
    if (holder->substruct != 0) {
        holder->substruct->width = width;
        holder->substruct->height = height;
    }
}
