#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
extern "C" int func_0202c508(void*);
void ClearBitField1(unsigned char* obj, int bit);
extern "C" void func_ov017_021ced48(int, int);

// USA: func_020e3798
ARM void ClearBitOrNotifyOverlay020e3798(unsigned char* obj) {
    void* state = func_0202ae18();
    if (!CheckField0NonZero((int*)state)) return;
    obj[2] = 0;
    if (func_0202c508(state)) {
        ClearBitField1(obj, 0);
        return;
    }
    func_ov017_021ced48(2, 0);
}
