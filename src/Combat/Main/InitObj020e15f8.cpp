#include <globaldefs.h>

struct FourShorts020e12a8;
void StoreFourShorts(struct FourShorts020e12a8* dst, short a, short b, short c, short d);

struct Struct_020e2bd8;
void Init020e2bd8(struct Struct_020e2bd8* obj, int arg1, int arg2);

// USA: func_020e15f8
ARM void InitObj020e15f8(char* obj, int arg1, int arg2) {
    *(int*)(obj + 0) = 0;
    *(int*)(obj + 4) = 0;
    *(unsigned char*)(obj + 8) = 0;
    int i;
    for (i = 0; i < 3; i++) {
        StoreFourShorts((struct FourShorts020e12a8*)(obj + 0xa + i * 8), 0, 0, 0, 0);
    }
    *(short*)(obj + 0x22) = 0x7fff;
    *(short*)(obj + 0x24) = 0xf0a;
    Init020e2bd8((struct Struct_020e2bd8*)(obj + 0x28), arg1, arg2);
}
