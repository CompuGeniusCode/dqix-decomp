#include <globaldefs.h>

// USA: func_ov000_0216f728
ARM int IsValueInRange0216f728(unsigned short* ptr) {
    int result = 0;
    if (ptr) {
        unsigned short v = *ptr;
        result = (unsigned int)(v - 9) <= 2;
    }
    return result;
}
