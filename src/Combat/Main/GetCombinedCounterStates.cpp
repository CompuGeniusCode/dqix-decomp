#include <globaldefs.h>

int GetField0x10StateIfField0x14Positive(int* obj);
int GetField0x1cStateIfField0x20Positive(int* obj);

// USA: func_0203b470
ARM unsigned short GetCombinedCounterStates(int* obj) {
    return (unsigned short)(GetField0x10StateIfField0x14Positive(obj)
                          | (GetField0x1cStateIfField0x20Positive(obj) << 8));
}
