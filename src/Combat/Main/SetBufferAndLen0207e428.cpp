#include <globaldefs.h>

struct Obj0207e428 {
    char unk[0x5c];
    void* buf;
    unsigned int len;
};

// USA: func_0207e428
ARM void SetBufferAndLen0207e428(struct Obj0207e428* obj, void* buf, unsigned int len) {
    obj->buf = buf;
    obj->len = len;
}
