#include <globaldefs.h>

struct BackgroundLoadRequest {
    unsigned char unknown0[0x14];
    int unknown14;
};

extern "C" void* func_020dfc2c(void* p);
extern "C" void ResetBackgroundLoadRequest(struct BackgroundLoadRequest* p);

extern "C" int CopyLocalizedStringFromArchive(int destBuffer, void* p1, int stringId, int unused, unsigned char lockLoader, int p5);

extern const char strStrbtlLgNat[];
extern const char strDataBinStrbtlGp2[];

// USA: CopyBattleString
// The file paths in this function's literal pool are "data/bin/strbtl.gp2" and "strbtl_<LG>.nat".
#pragma opt_propagation off
// Copies one battle string into buf. CopyLocalizedStringFromArchive pulls the "strbtl_<LG>.nat"
// member out of "data/bin/strbtl.gp2" and copies the entry the first argument names, holding the
// BackgroundLoader lock while it does; buf is cleared first, so a miss leaves an empty string.
// That first argument is a lookup key rather than a length: it reaches func_020e046c as the index
// handed to LookupFieldByKey020e0440, and the copy there is a strcpy with no bound, so the caller's
// buffer has to be large enough on its own. The local request is reset twice -- func_020dfc2c
// resets it and returns it, then ResetBackgroundLoadRequest resets it again -- and is never read.
// CopyActexpString is the same function over "data/prm/actexp.gp2".
extern "C" ARM void CopyBattleString(int stringId, char* buf) {
    if (stringId >= 0 && buf != NULL) {
        struct BackgroundLoadRequest request;
        void* p1;
        int p5;
        p5 = (int)strDataBinStrbtlGp2;
        p1 = (void*)strStrbtlLgNat;
        buf[0] = 0;
        func_020dfc2c(&request);
        ResetBackgroundLoadRequest(&request);
        CopyLocalizedStringFromArchive((int)buf, p1, stringId, 0, 1, p5);
    }
}
