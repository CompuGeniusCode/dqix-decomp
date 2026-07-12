#include <globaldefs.h>

extern "C" void func_0206b104(void* obj);
extern "C" void func_0206b224(void* obj, int val);

// USA: func_02065920
ARM void ResetOrConsumeCounter02065920(unsigned char* obj, unsigned int amount) {
    if ((obj + 0x1000)[0x9d0] != 0 || *(int*)(obj + 0x9a0) != 4) return;
    obj[0x912] = 0;
    if (amount < (obj + 0x1000)[0x95f]) {
        (obj + 0x1000)[0x95f] -= amount;
        return;
    }
    (obj + 0x1000)[0x95f] = 0;
    (obj + 0x1000)[0x9ae] = 0;
    (obj + 0x1000)[0x9af] = 0;
    (obj + 0x1000)[0x9cd] = 1;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
    func_0206b104(obj);
    *(int*)(obj + 0x9a0) = 5;
    func_0206b224(obj, 5);
}
