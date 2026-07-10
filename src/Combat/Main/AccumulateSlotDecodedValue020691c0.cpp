#include <globaldefs.h>

int FindFirstDigitAndParse(signed char* s);
extern "C" int func_02003ce8(int value, void* slot);

struct Slot020691c0 { unsigned char data[0x40]; };

// USA: func_020691c0
ARM void AccumulateSlotDecodedValue020691c0(signed char* s, int* accum, char* base) {
    int idx = FindFirstDigitAndParse(s) - 1;
    struct Slot020691c0* slot = (struct Slot020691c0*)(base + 0x2ec) + idx;
    if (slot != NULL) {
        *accum += func_02003ce8(*accum, slot);
    }
}
