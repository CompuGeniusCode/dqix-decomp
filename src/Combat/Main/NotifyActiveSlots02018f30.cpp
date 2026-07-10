#include <globaldefs.h>

extern "C" void func_020b726c(void*, unsigned short);

// USA: func_02018f30
ARM void NotifyActiveSlots02018f30(unsigned char* obj) {
    int i;
    for (i = 0; i < 2; i++) {
        void* p = *(void**)(obj + i * 0xac + 0x4ec);
        if (p != NULL) {
            func_020b726c(p, *(unsigned short*)(obj + 0x36));
        }
    }
}
