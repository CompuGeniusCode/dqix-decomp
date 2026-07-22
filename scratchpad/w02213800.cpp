#include <globaldefs.h>

struct Obj022133f8 {
    char pad[0xd0c];
    unsigned char field : 4;
};

extern "C" Obj022133f8* func_ov031_022133f8(int a0);
int IsEqualToData8_022157c4(void* p);
int IsEqualToData8_02215718(int a);

struct Arg02213800 {
    char pad[0x2c];
    unsigned short field2c;
};

// USA: func_ov031_02213800
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02213800(Arg02213800* obj) {
    Obj022133f8* h = func_ov031_022133f8(0x10);
    if (h->field != 0 && h->field != 4) goto check5;
    if (((obj->field2c >> 4) & 1) != 1) goto check5;
    if (IsEqualToData8_022157c4((char*)obj + 0xc) == 1) return 6;
check5:
    if (h->field != 0 && h->field != 5) goto fail;
    if (((obj->field2c >> 4) & 1) != 1) goto fail;
    if (IsEqualToData8_02215718((int)((char*)obj + 0xc)) == 1) return 7;
fail:
    return -1;
}
