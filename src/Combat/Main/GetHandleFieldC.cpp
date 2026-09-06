#include <globaldefs.h>

struct HandleFieldC_02097240 {
    int pad0;
    int pad4;
    int pad8;
    short value;
};

// USA: func_02097240
ARM short GetHandleFieldC(struct HandleFieldC_02097240* obj) {
    return obj->value;
}
