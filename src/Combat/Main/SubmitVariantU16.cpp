#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

extern "C" void func_020724f4(int a, int b, int c);

struct Data02108da8 {
    int f0;
    int f4;
};

extern struct Data02108da8 data_02108da8;

// USA: func_0207236c
ARM int SubmitVariantU16(struct Variant02030b0c* p) {
    func_020724f4(data_02108da8.f4, data_02108da8.f0, (unsigned short)GetIntFromVariant02030b0c(p));
    return 1;
}
