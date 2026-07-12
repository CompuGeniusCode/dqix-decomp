#include <globaldefs.h>

struct DeltaSelectorState020ccc10;
ARM int CheckStateByType020d8a68(unsigned char* obj);
ARM int AddDeltaBySelectorClampAt0x2c(struct DeltaSelectorState020ccc10* s, int value, int mode);

// USA: func_020d8ae8
ARM int TryApplySelectorDelta020d8ae8(unsigned char* obj, int value) {
    if (!CheckStateByType020d8a68(obj)) {
        return 0;
    }
    switch (*(unsigned short*)obj) {
    case 1:
        return AddDeltaBySelectorClampAt0x2c((struct DeltaSelectorState020ccc10*)(obj + 4), value, 0) != 0;
    case 2:
        return 0;
    default:
        return 0;
    }
}
