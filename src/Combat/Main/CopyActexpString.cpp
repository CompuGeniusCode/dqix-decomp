#include <globaldefs.h>

struct BackgroundLoadRequest {
    unsigned char unknown0[0x14];
    int unknown14;
};

extern "C" void* func_020dfc2c(void* request);
extern "C" void ResetBackgroundLoadRequest(struct BackgroundLoadRequest* request);

extern "C" int CopyLocalizedStringFromArchive(int destBuffer, void* fileName, int maxLength, int unknownArg4, unsigned char lockLoader, int archivePath);

extern const char strDataPrmActexpGp2[];
extern const char strActexpLgNat[];

// USA: func_020dd040
// The file paths in this function's literal pool are "data/prm/actexp.gp2" and "actexp_<LG>.nat".
#pragma opt_propagation off
// USA: CopyActexpString
// The request the two setup calls fill in is a stack object nothing reads afterwards; what does the
// work is CopyLocalizedStringFromArchive, whose fifth argument -- 1 here -- is what makes it hold
// the BackgroundLoader lock across the read, and whose fourth is 0 at both call sites and is not
// established. CopyBattleString is the same routine over data/bin/strbtl.gp2 and "strbtl_<LG>.nat",
// differing only in accepting a length of zero.
extern "C" ARM void CopyActexpString(int len, char* buf) {
    if (len > 0 && buf != NULL) {
        struct BackgroundLoadRequest request;
        void* fileName;
        int archivePath;
        archivePath = (int)strDataPrmActexpGp2;
        fileName = (void*)strActexpLgNat;
        buf[0] = 0;
        func_020dfc2c(&request);
        ResetBackgroundLoadRequest(&request);
        CopyLocalizedStringFromArchive((int)buf, fileName, len, 0, 1, archivePath);
    }
}
