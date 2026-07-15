#include <globaldefs.h>

void SetAllEntriesField0xcBits24To29(void* obj, unsigned int value);

// USA: func_ov017_021923e0
ARM void SetAllEntriesFieldits24To29IfField54_021923e0_021923e0(void* obj, unsigned int value) {
    void* q = *(void**)((char*)obj + 0x8);
    if (q == NULL) {
        return;
    }
    void* p = *(void**)((char*)q + 0x54);
    if (p == NULL) {
        return;
    }
    SetAllEntriesField0xcBits24To29(p, value);
}
