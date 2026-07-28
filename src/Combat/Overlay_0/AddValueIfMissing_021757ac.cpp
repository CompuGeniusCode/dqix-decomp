#include <globaldefs.h>

// USA: func_ov000_021757ac  (semantic: AddValueIfMissing_021757ac)
extern "C" ARM void func_ov000_021757ac(char* obj, unsigned short value) {
    int found = 0;
    unsigned short* arr = (unsigned short*)(obj + 0x10);
    signed char i;
    signed char count = *(signed char*)(obj + 0x1a);
    for (i = 0; i < count; i++) {
        if (value == arr[i]) {
            found = 1;
        }
    }
    if (!found) {
        *(signed char*)(obj + 0x1a) = *(volatile signed char*)(obj + 0x1a) + 1;
        arr[count] = value;
    }
}
