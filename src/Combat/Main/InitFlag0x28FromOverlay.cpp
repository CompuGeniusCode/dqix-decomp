#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_0203af44(void*);
extern "C" void func_0203af48(void*);
extern "C" void func_0203b080(void*);

struct Struct020db814 {
    char pad[0x28];
    unsigned char field0x28;
};

// USA: func_020db814
ARM void InitFlag0x28FromOverlay(void) {
    struct Struct020db814* obj = (struct Struct020db814*)func_ov017_0218b5b0();
    if (obj == NULL) {
        return;
    }
    obj->field0x28 = 1;
    func_0203af44(obj);
    func_0203af48(obj);
    func_0203b080(obj);
}
