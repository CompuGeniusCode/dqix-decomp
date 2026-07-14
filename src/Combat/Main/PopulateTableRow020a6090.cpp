#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct TableRow020a6090 { unsigned short v[16]; };
extern struct TableRow020a6090 data_02109dcc[];

// USA: func_020a6090
ARM int PopulateTableRow020a6090(void* param) {
    unsigned char index = (unsigned short)GetIntFromVariant02030b0c((struct Variant02030b0c*)param);
    struct TableRow020a6090* e = &data_02109dcc[index];
    e->v[0] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x8));
    e->v[1] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x10));
    e->v[2] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x18));
    e->v[3] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x20));
    e->v[4] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x28));
    e->v[5] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x30));
    e->v[6] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x38));
    e->v[7] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x40));
    e->v[8] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x48));
    e->v[9] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x50));
    e->v[10] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x58));
    e->v[11] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x60));
    e->v[12] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x68));
    e->v[13] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x70));
    e->v[14] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x78));
    e->v[15] = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param + 0x80));
    return 1;
}
