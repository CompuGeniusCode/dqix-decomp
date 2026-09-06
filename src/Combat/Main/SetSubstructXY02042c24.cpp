#include <globaldefs.h>

struct Substruct02042c24 {
    unsigned short x;
    unsigned short y;
};

struct Holder02042c24 {
    char unk[0x440];
    struct Substruct02042c24* substruct;
};

// USA: func_02042c24
ARM void SetSubstructXY02042c24(struct Holder02042c24* holder, int x, int y) {
    if (holder->substruct != 0) {
        holder->substruct->x = x;
        holder->substruct->y = y;
    }
}
