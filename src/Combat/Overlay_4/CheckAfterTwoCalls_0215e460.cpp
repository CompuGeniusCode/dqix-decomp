#include <globaldefs.h>

extern "C" void func_ov017_0218b5b0(void);
extern "C" int func_ov017_021bdbcc(void);

// USA: func_ov004_0215e460
ARM int CheckAfterTwoCalls_0215e460(void) {
    func_ov017_0218b5b0();
    return func_ov017_021bdbcc() != 0;
}
