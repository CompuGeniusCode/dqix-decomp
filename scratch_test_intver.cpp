#include <globaldefs.h>
extern "C" int func_ov017_0218b5b0(void);
extern "C" void CopyInternalFields0207df50(void*);
extern "C" void RestorePairTables0207df90(void*);
extern "C" void BackupPairTables0207dfac(void*);
extern "C" void other(void);

extern "C" int fintver(void* obj) {
    int rawval = func_ov017_0218b5b0();
    char* base2 = (char*)(rawval + 0x2cc);
    CopyInternalFields0207df50(base2);
    RestorePairTables0207df90(base2);
    other();
    BackupPairTables0207dfac(base2);
    return 0;
}
