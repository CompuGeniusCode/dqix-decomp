#include <globaldefs.h>

// Reports the stylus position: the live sample at +0x20/+0x22 while the panel's touch field at
// +0x24 is set, otherwise the ints at +0x38/+0x3c, which func_02012538 refreshes from +0x20/+0x22
// on both of its branches every frame, so that fallback is the last latched sample and not a value
// held over from an older touch. The object is the touch panel manager, a singleton parked in
// data_020fb3cc -- +0x0 is the four-entry auto-sampling buffer, +0x20 a TPData, +0x28 the
// calibration parameters -- and func_02012b54 throws the result out beyond x 2..253 or y 2..189.
extern "C" ARM void GetTouchPoint(unsigned char* obj, int* out1, int* out2) {
    if (*(unsigned short*)(obj + 0x24) != 0) {
        *out1 = *(unsigned short*)(obj + 0x20);
        *out2 = *(unsigned short*)(obj + 0x22);
    } else {
        *out1 = *(int*)(obj + 0x38);
        *out2 = *(int*)(obj + 0x3c);
    }
}
