#include <globaldefs.h>

struct B190Outer;
int GetBits12To15(int unused, struct B190Outer* obj);

// USA: func_0205af18
ARM unsigned short GetBits12To15Clamped(int unused, struct B190Outer* obj) {
    if (obj == 0) {
        return 0;
    }
    return GetBits12To15(unused, obj);
}
