#include <globaldefs.h>

struct Struct020db9a8;
int GetSwapBitIfFlag54Clear(struct Struct020db9a8* obj);

extern "C" void* func_0203bd08(void* obj);
void SetByteAt0xc0203be58(char*, int, int);

// USA: func_020db360
ARM void SyncSwapBitState020db360(struct Struct020db9a8* obj, int b) {
    void* obj2 = func_0203bd08(obj);
    int swapBit = GetSwapBitIfFlag54Clear(obj);
    SetByteAt0xc0203be58((char*)obj2, swapBit & 0xff, b);
    SetByteAt0xc0203be58((char*)obj2, (swapBit ^ 1) & 0xff, 1);
}
