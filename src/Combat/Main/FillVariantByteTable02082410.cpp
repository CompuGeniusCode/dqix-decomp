#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct Holder02108ee8 {
    char pad[0x3c];
    unsigned char arr[0x16];
};
struct GlobalTable02108ee8 {
    int unk0;
    int unk4;
    int unk8;
    struct Holder02108ee8* holder;
};
extern GlobalTable02108ee8 data_02108ee8;

// USA: func_02082410
ARM int FillVariantByteTable02082410(struct Variant02030b0c* elem) {
    int i;
    for (i = 0; i < 0x11; i++) {
        data_02108ee8.holder->arr[i] = (unsigned char)GetIntFromVariant02030b0c(elem);
        elem = (struct Variant02030b0c*)((char*)elem + 8);
    }
    int j;
    for (j = 0x11; j < 0x16; j++) {
        data_02108ee8.holder->arr[j] = 0x64;
    }
    return 1;
}
