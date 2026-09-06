#include <globaldefs.h>
typedef void (*Handler020e2c34)(int, int, int, int);
extern Handler020e2c34 data_020f2bf4[][2];
struct Entry020e2c7c;
void DispatchEntryHandlers020e2c7c(struct Entry020e2c7c* obj);
struct Entry020e2c34 {
    unsigned char state;
    unsigned char type;
    unsigned char subtype;
    unsigned char pad3;
    char pad[0x10];
    int w14;
    int w18;
    int w1c;
    int w20;
};
// USA: func_020e2c34
ARM void UpdateAndDrawEntry020e2c34(struct Entry020e2c34* obj) {
    if (obj->state == 0) return;
    DispatchEntryHandlers020e2c7c((struct Entry020e2c7c*)obj);
    data_020f2bf4[obj->type][obj->subtype](obj->w14, obj->w18, obj->w1c, obj->w20);
}
