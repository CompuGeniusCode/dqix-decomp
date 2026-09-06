#include <globaldefs.h>

struct Struct_0205ba2c;
void InitStruct_0205ba2c(struct Struct_0205ba2c*);

struct Struct_0205bbcc {
    char base[0x30];
    int field30;
    int field34;
    short field38;
    short field3a;
    int field3c;
    int field40;
    int field44;
    int field48;
    unsigned char field4c;
    unsigned char field4d;
    unsigned char field4e;
};

// USA: func_0205bbcc
ARM void Init0205bbcc(struct Struct_0205bbcc* s) {
    InitStruct_0205ba2c((struct Struct_0205ba2c*)s);
    s->field30 = -1;
    s->field34 = 0;
    s->field38 = 0;
    s->field3a = 0;
    s->field3c = 0;
    s->field40 = 0;
    s->field44 = 0;
    s->field48 = 0;
    s->field4c = 0;
    s->field4d = 0;
    s->field4e = 0;
}
