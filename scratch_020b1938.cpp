#include <globaldefs.h>

struct Obj020b1938 {
    int field0;
    int field4;
    int field8;
    unsigned char fieldC;
    char pad[3];
    int field10;
};

extern "C" void func_020ca458(unsigned int fillWord, int pos, int stepA);

// USA: func_020b1938
ARM void FillTileRows020b1938(struct Obj020b1938* obj, unsigned int value) {
    unsigned int fillWord = value;
    int pos = obj->field0;
    if (obj->fieldC == 4) {
        fillWord = fillWord | (fillWord << 4);
        fillWord = fillWord | (fillWord << 8);
    } else {
        fillWord = fillWord | (fillWord << 8);
    }
    fillWord |= fillWord << 16;
    int stride = (obj->fieldC << 6) / 8;
    int stepA = stride * obj->field4;
    int stepB = stride * obj->field10;
    if (obj->field8 <= 0) {
        return;
    }
    int i = 0;
    do {
        func_020ca458(fillWord, pos, stepA);
        pos += stepB;
        i++;
    } while (i < obj->field8);
}
