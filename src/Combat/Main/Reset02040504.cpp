#include <globaldefs.h>

ARM void Init020404c0(int* obj);

// USA: func_02040504
ARM void Reset02040504(int* obj) {
    obj[5] = 0;
    obj[6] = 0;
    obj[7] = 0;
    Init020404c0(obj);
}
