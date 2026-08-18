#include <globaldefs.h>
#pragma define_section initcode ".init" RX

extern "C" void _Z38InitTwoSubObjectsWithCallbacks0203a878Pv(void* obj);
class Container0203a54c;
void InitSubObjectArraysReturnSelf(Container0203a54c* obj);

struct Node0200efd0 {
    struct Node0200efd0* next;
    int b;
    int c;
};

extern "C" void func_0200efd0(int c, int b, struct Node0200efd0* node);

extern int data_02104b6c;
extern struct Node0200efd0 data_02104b60;

// USA: func_020e5c00  (semantic: InitEntries020e5c00)
extern "C" __declspec(initcode) ARM void func_020e5c00(void) {
    _Z38InitTwoSubObjectsWithCallbacks0203a878Pv(&data_02104b6c);
    func_0200efd0((int)&data_02104b6c, (int)InitSubObjectArraysReturnSelf, &data_02104b60);
}
