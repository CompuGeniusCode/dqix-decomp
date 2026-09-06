#include <globaldefs.h>

struct Info021e1f0c {
    char pad[8];
    unsigned int race : 4;
    unsigned int kind : 5;
};

struct Elem021e1f0c {
    char pad0[4];
    struct Info021e1f0c* info;
    char pad1[6];
    unsigned char bit0 : 1;
    unsigned char active : 1;
    unsigned char rest : 6;
    char pad2[1];
};

struct FooObj021e1f0c {
    char pad0[4];
    struct Elem021e1f0c* list;
    short num;
};

// USA: func_ov023_021e1f0c
extern "C" ARM int func_ov023_021e1f0c(FooObj021e1f0c* obj, short mode, short p2, short p3) {
    short num = obj->num;
    short result = 0;
    switch (mode) {
    case 0:
        for (short idx = 8; idx <= 9; idx++) {
            result += func_ov023_021e1f0c(obj, -1, idx, -1);
        }
        return result;
    case 1:
    case 2:
    default:
        break;
    }

    struct Elem021e1f0c* list = obj->list;
    for (short i = 0; i < num; i++) {
        struct Elem021e1f0c* elem = &list[i];
        if (elem->active) {
            struct Info021e1f0c* info = elem->info;
            if (info != 0) {
                if (p2 >= 0 && p3 >= 0) {
                    if (p2 == (short)info->race && p3 == (short)info->kind) result++;
                } else if (p2 >= 0) {
                    if (p2 == (short)info->race) result++;
                } else if (p3 >= 0) {
                    if (p3 == (short)info->kind) result++;
                }
            }
        }
    }
    return result;
}
