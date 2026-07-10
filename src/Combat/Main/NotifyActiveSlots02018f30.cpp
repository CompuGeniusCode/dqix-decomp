#include <globaldefs.h>

void SetAllEntriesField0x4Low15Bits(void*, unsigned int);

// USA: func_02018f30
ARM void NotifyActiveSlots02018f30(unsigned char* obj) {
    int i;
    for (i = 0; i < 2; i++) {
        void* p = *(void**)(obj + i * 0xac + 0x4ec);
        if (p != NULL) {
            SetAllEntriesField0x4Low15Bits(p, *(unsigned short*)(obj + 0x36));
        }
    }
}
