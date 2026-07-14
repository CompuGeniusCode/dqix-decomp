#include <globaldefs.h>

extern unsigned char data_02114e54;

struct FlagWord02046708;

void* GetDataPtr02114e04_020d6c00(void);
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
int GetGlobalField0x1c020421a0();
extern "C" void func_02096c38(void* obj, int a0, int a1, int a2, int a3);

// USA: func_02096824
ARM void MaybeDispatchPendingAction02096824(unsigned char* obj) {
    void* p = GetDataPtr02114e04_020d6c00();
    if (TestFlags02046708((struct FlagWord02046708*)p, 0x4000)) return;
    if (!((&data_02114e54)[0x5f] != 0 && *(unsigned short*)(&data_02114e54 + 0x24) != 0)) return;
    int g = GetGlobalField0x1c020421a0();
    if (g != 0 && *(int*)(g + 0x998) != 0) return;
    if (!obj[0x225]) return;
    func_02096c38(obj, obj[0x220], obj[0x221], obj[0x222], obj[0x223]);
}
