#include <globaldefs.h>

struct Struct020dfc40 {
    unsigned char pad[0x14];
    int field_14;
};

extern "C" void* func_020dfc2c(void* p);
extern "C" void ResetBackgroundLoadRequest(struct Struct020dfc40* p);

extern "C" int CopyLocalizedStringFromArchive(int p0, void* p1, int p2, int p3, unsigned char p4, int p5);

extern const char strStrbtlLgNat[];
extern const char strDataBinStrbtlGp2[];

// USA: CopyBattleString
// The file paths in this function's literal pool are "data/bin/strbtl.gp2" and "strbtl_<LG>.nat".
#pragma opt_propagation off
// USA: CopyBattleString
extern "C" ARM void CopyBattleString(int len, char* buf) {
    if (len >= 0 && buf != NULL) {
        struct Struct020dfc40 s;
        void* p1;
        int p5;
        p5 = (int)strDataBinStrbtlGp2;
        p1 = (void*)strStrbtlLgNat;
        buf[0] = 0;
        func_020dfc2c(&s);
        ResetBackgroundLoadRequest(&s);
        CopyLocalizedStringFromArchive((int)buf, p1, len, 0, 1, p5);
    }
}
