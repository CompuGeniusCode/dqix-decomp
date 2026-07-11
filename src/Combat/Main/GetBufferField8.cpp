#include <globaldefs.h>

struct BufferField8_02097418 {
    int pad0;
    int pad4;
    void* value;
};

// USA: func_02097418
ARM void* GetBufferField8(struct BufferField8_02097418* obj) {
    return obj->value;
}
