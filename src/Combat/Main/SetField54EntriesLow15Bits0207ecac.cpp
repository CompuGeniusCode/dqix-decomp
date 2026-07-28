#include <globaldefs.h>

void SetAllEntriesField0x4Low15Bits(void* obj, unsigned int value);

// USA: func_0207ecac  (semantic: SetField54EntriesLow15Bits_0207ecac)
extern "C" ARM void func_0207ecac(void* obj, unsigned int value) {
    void* p = *(void**)((char*)obj + 0x54);
    if (!p) return;
    SetAllEntriesField0x4Low15Bits(p, value);
}
