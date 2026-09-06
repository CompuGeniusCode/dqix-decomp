#include <globaldefs.h>
extern "C" int func_ov017_0218b5b0(void);
extern "C" void CopyInternalFields0207df50(void*);
extern "C" void RestorePairTables0207df90(void*);

extern "C" int f2calls(void* obj) {
    int rawval = func_ov017_0218b5b0();
    char* base2 = (char*)(rawval + 0x2cc);
    CopyInternalFields0207df50(base2);
    RestorePairTables0207df90(base2);
    return 0;
}
