#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" unsigned short* func_02012fe4(void);

struct Obj0208b4d4 {
    char pad[0xac];
    int captured;   // 0xac
    int done;       // 0xb0
};

// USA: func_0208b4d4
ARM int ValidateCapturedValue0208b4d4(struct Obj0208b4d4* obj) {
    unsigned short cur;
    func_ov017_0218b5b0();
    cur = *func_02012fe4();
    if (cur != obj->captured) {
        obj->done = 0;
        obj->captured = -1;
    }
    return obj->done;
}
