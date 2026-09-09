#include <globaldefs.h>

struct Struct020dfc40 {
    unsigned char pad[0x14];
    int field_14;
};

extern "C" void* func_020dfc2c(void* p);
extern "C" void ResetBackgroundLoadRequest(struct Struct020dfc40* p);

extern "C" int CopyLocalizedStringFromArchive(int p0, void* p1, int p2, int p3, unsigned char p4, int p5);

extern const char strDataPrmActexpGp2[];
extern const char strActexpLgNat[];

// USA: func_020dd040
// The file paths in this function's literal pool are "data/prm/actexp.gp2" and "actexp_<LG>.nat".
#pragma opt_propagation off
// USA: CopyActexpString
extern "C" ARM void CopyActexpString(int len, char* buf) {
    if (len > 0 && buf != NULL) {
        struct Struct020dfc40 s;
        void* p1;
        int p5;
        p5 = (int)strDataPrmActexpGp2;
        p1 = (void*)strActexpLgNat;
        buf[0] = 0;
        func_020dfc2c(&s);
        ResetBackgroundLoadRequest(&s);
        CopyLocalizedStringFromArchive((int)buf, p1, len, 0, 1, p5);
    }
}
