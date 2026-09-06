#include <globaldefs.h>

struct Elem_021e1bac {
    char pad0[0xa];
    unsigned short score;
    char pad_c[0xe - 0xc];
    unsigned char skip : 1;
    unsigned char pad_bit1 : 1;
    unsigned char category : 6;
    unsigned char fieldF;
};

struct Obj021e1bac {
    char pad0[4];
    Elem_021e1bac* arr;
    short count;
};

// USA: func_ov023_021e1bac
extern "C" ARM void* func_ov023_021e1bac(Obj021e1bac* obj, int b, int c, int d) {
    unsigned short bestScore = 0xffff;
    Elem_021e1bac* el;
    Elem_021e1bac* best = 0;
    Elem_021e1bac* arr = obj->arr;
    short count = obj->count;
    for (short i = 0; i < count; i++) {
        el = &arr[i];
        if (el->skip) continue;
        if (bestScore < el->score) continue;
        if (b == 0) {
            int ok = (el->category <= 7);
            if (!ok) continue;
        } else if (c >= 0 && d >= 0) {
            if (el->fieldF != d) continue;
            if (el->category != c) continue;
        } else if (c >= 0) {
            if (el->category != c) continue;
        } else if (d >= 0) {
            if (el->fieldF != d) continue;
        }
        bestScore = el->score;
        best = el;
    }
    if (best != 0) {
        best->skip = 1;
    }
    return best;
}
