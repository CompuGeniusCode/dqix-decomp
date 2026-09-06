#include <globaldefs.h>

struct Foo0207df50;
ARM void CopyInternalFields0207df50(struct Foo0207df50 *p);
ARM void RestorePairTables0207df90(char* obj);
ARM void BackupPairTables0207dfac(char* obj);
extern "C" void func_0207de48(void* p, int a, int b);

struct PairEntry020543ec { int a; int b; };
extern struct PairEntry020543ec data_020e7ce0[];
extern struct PairEntry020543ec data_020e7ce4[];

// USA: func_020543ec
ARM void InitSlotEntries020543ec(char* obj, char* p) {
    int i;
    CopyInternalFields0207df50((struct Foo0207df50*)p);
    RestorePairTables0207df90(p);
    for (i = 0; i < 10; i++) {
        func_0207de48(obj + 0xcc + i * 0x70, data_020e7ce0[i].a, data_020e7ce4[i].a);
    }
    func_0207de48(obj + 0x168 + 0x400, 0x240, 0x20);
    BackupPairTables0207dfac(p);
}
