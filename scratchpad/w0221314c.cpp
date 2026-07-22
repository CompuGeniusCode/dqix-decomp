#include <globaldefs.h>
#include "System/Memory.h"

struct HandlerSlot_0221314c {
    char pad0[0x40];
    char name[0x20];
    char pad1[0x80 - 0x60];
    char data[0x10];
    char pad2[0xe6 - 0x90];
    unsigned char field_e6;
    char pad3[0xd0c - 0xe7];
    unsigned char field_d0c : 4;
};

extern "C" HandlerSlot_0221314c* func_ov031_022133f8(unsigned int flags);

// USA: func_ov031_0221314c
#pragma optimize_for_size off
extern "C" ARM void InitHandlerSlotFromNameAndData_0221314c(const unsigned char* name, char* data, int mode) {
    HandlerSlot_0221314c* h = func_ov031_022133f8(0x10);
    h->field_d0c = 1;
    VectorizedMemset(h, 0, 0xf0);
    int i = 0;
    do {
        unsigned char c = name[i];
        if (c == 0) break;
        h->name[i++] = c;
    } while (i < 0x20);
    if (data == 0 || mode == 0) {
        h->field_e6 = h->field_e6 & ~3;
        return;
    }
    int len;
    if (mode == 1) len = 5;
    else if (mode == 2) len = 0xd;
    else len = 0x10;
    VectorizedInvertedMemcpy(data, h->data, len);
    h->field_e6 = (h->field_e6 & ~3) | ((unsigned char)mode & 3);
}
