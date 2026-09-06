#include <globaldefs.h>
extern "C" void* func_ov011_021845f8(void*, int);
extern "C" char* func_ov017_0218b5b0(void);
extern "C" void* AddOffset20_021f7318(void*);
extern "C" void CopyInternalFields0207df50(void*);
extern "C" void RestorePairTables0207df90(void*);
extern "C" void func_0204719c(void*);
extern "C" void BackupPairTables0207dfac(void*);

extern "C" int fvoidptr(void* obj) {
    void* base = func_ov011_021845f8(obj, 6);
    if (!base) return 0;
    void* block = func_ov011_021845f8(base, 0xac);
    if (!block) return 0;
    void* base2 = func_ov017_0218b5b0() + 0x2cc;
    void* p20 = AddOffset20_021f7318(block);
    CopyInternalFields0207df50(base2);
    RestorePairTables0207df90(base2);
    func_0204719c(p20);
    BackupPairTables0207dfac(base2);
    return 0;
}
