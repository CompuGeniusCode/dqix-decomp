#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
extern "C" int func_020bb7cc(int a, int b, int c);

struct PairBlock0216733c { unsigned int v[2]; };
struct Foo0216733c {
    char pad[0x58];
    struct PairBlock0216733c p1;
    struct PairBlock0216733c p2;
};

// USA: func_ov000_0216733c  (semantic: SyncPairTablesAndFill_0216733c)
extern "C" ARM void func_ov000_0216733c(char* arg0) {
    func_ov017_0218b5b0();
    struct Foo0216733c* foo = (struct Foo0216733c*)(arg0 + 0x1bc);
    foo->p2 = foo->p1;
    RestorePairTables0207df90(arg0 + 0x1bc);

    unsigned char byteVal = *(unsigned char*)(*(char**)(arg0 + 0x29c) + 0x8000 + 0x1b0);
    int val = byteVal;
    int mult;
    if (val > 5) {
        mult = 0x100;
        *(unsigned char*)(arg0 + 0x5000 + 0xe00) = 8;
    } else {
        *(unsigned char*)(arg0 + 0x5000 + 0xe00) = 5;
        mult = 0x190;
    }

    int i;
    for (i = 0; i < *(unsigned char*)(arg0 + 0x5000 + 0xe00); i++) {
        *(int*)(arg0 + i * 4 + 0x5000 + 0xe04) = func_020bb7cc(mult, 0, 0);
    }

    BackupPairTables0207dfac(arg0 + 0x1bc);
    *(unsigned char*)(arg0 + 0x5000 + 0xe01) = 0;
}
