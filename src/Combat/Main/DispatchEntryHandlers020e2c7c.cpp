#include <globaldefs.h>
typedef void (*Handler020e2c7c)(int, int);
extern Handler020e2c7c data_020f2c04[][2];
extern Handler020e2c7c data_020f2be4[];
struct Entry020e2c7c {
    unsigned char pad0;
    unsigned char type;
    unsigned char subtype;
    unsigned char pad3;
    int w4;
    int w8;
    int wc;
    int w10;
};
// USA: func_020e2c7c
ARM void DispatchEntryHandlers020e2c7c(struct Entry020e2c7c* obj) {
    data_020f2c04[obj->type][obj->subtype](obj->w4, obj->w8);
    data_020f2be4[obj->type](obj->wc, obj->w10);
}
