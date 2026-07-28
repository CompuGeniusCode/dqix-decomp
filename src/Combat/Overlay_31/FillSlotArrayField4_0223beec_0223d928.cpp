#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" void func_020ca458(unsigned int value, void* dest, int count);
extern char* data_ov031_02290d60;
ARM int FillSlotArrayField4_0223beec(int n, int base, int stride);
void* CallWithZeroExtra_0223e218(void* a, void* b, void* c, int d);
ARM void FlushAndTransferOam_0223d9c4(void);

// USA: func_ov031_0223d928  (semantic: AllocAndFillOamSlots_0223d928)
extern "C" ARM void func_ov031_0223d928(void) {
    void* p = func_ov031_0223cf4c(0x80c, 4);
    data_ov031_02290d60 = (char*)p;
    func_020ca458(0x200, p, 0x800);
    int i = 0;
    int offset = 0;
    do {
        int r = FillSlotArrayField4_0223beec(0x40, (int)(data_ov031_02290d60 + offset), 8);
        *(int*)(data_ov031_02290d60 + i * 4 + 0x800) = r;
        i++;
        offset += 0x400;
    } while (i < 2);
    void* result = CallWithZeroExtra_0223e218((void*)1, (void*)FlushAndTransferOam_0223d9c4, 0, 0xc8);
    *(int*)(data_ov031_02290d60 + 0x808) = (int)result;
}
