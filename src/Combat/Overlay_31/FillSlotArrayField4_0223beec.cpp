#include <globaldefs.h>

struct Ctx0223bf48 { unsigned short field0; unsigned char field2; unsigned char field3; };
extern "C" Ctx0223bf48* func_ov031_0223beb8(int n);

// USA: func_ov031_0223beec
ARM void FillSlotArrayField4_0223beec(int n, int base, int stride) {
    Ctx0223bf48* arr = func_ov031_0223beb8(n);
    int i = 0;
    if (n > 0) {
        do {
            *(int*)((char*)arr + 4 + i * 4) = base;
            i++;
            base += stride;
        } while (i < n);
    }
    arr->field3 = n;
}
