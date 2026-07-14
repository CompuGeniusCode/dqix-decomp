#include <globaldefs.h>

extern "C" void func_02034b34(void* p, int a, int b);

struct Struct020372b8 {
    char pad[0x40];
    unsigned char lo3 : 3;
    unsigned char field5 : 5;
    char pad2[0x2f];
    unsigned short f70;
};

// USA: func_020372b8
ARM void ScaleColorChannel020372b8(struct Struct020372b8* obj, int a, int b) {
    float f = (float)(unsigned int)obj->field5;
    f = f / 31.0f;
    f = f * 65535.0f;
    obj->f70 = (unsigned int)f;
    func_02034b34(&obj->f70, a, b);
}
