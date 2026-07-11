#include <globaldefs.h>

struct Struct020db9a8;
int GetSwapBitIfFlag54Clear(struct Struct020db9a8* obj);

extern "C" void* func_0203bd08(void* obj);
extern "C" void func_0203be58(void* obj2, int flag, int b);

// USA: func_020db360
ARM void SyncSwapBitState020db360(struct Struct020db9a8* obj, int b) {
    void* obj2 = func_0203bd08(obj);
    int swapBit = GetSwapBitIfFlag54Clear(obj);
    func_0203be58(obj2, swapBit & 0xff, b);
    func_0203be58(obj2, (swapBit ^ 1) & 0xff, 1);
}
