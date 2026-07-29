#include <globaldefs.h>
ARM unsigned int TestShift(unsigned int base, unsigned int j) {
    return base | ((j & 7) << 22);
}
