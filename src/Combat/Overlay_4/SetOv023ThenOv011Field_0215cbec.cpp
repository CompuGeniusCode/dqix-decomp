#include <globaldefs.h>

extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov023_021f65d4(void* obj, int a, int b);

// USA: func_ov004_0215cbec
ARM int SetOv023ThenOv011Field_0215cbec(void* obj) {
    func_ov023_021f65d4(obj, 2, 8);
    func_ov011_021848a0(obj, 0x68);
    return 0;
}
