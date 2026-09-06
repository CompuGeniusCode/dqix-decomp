#include <globaldefs.h>

struct AxisFloats0203b5a0;
int IsAxisIntWithin16(struct AxisFloats0203b5a0*, int);

// USA: func_0203b5e0
ARM int IsChannelValueZero0203b5e0(void* obj, int sel) {
    return IsAxisIntWithin16((struct AxisFloats0203b5a0*)obj, sel) == 0;
}
