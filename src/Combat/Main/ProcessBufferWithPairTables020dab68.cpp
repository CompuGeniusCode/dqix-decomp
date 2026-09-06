#include <globaldefs.h>

struct Pair020dab68 { int a; int b; };

void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
extern "C" int func_02057924(void);
extern "C" int func_02057e6c(int, int, int, int, int, int);

// USA: func_020dab68
ARM int ProcessBufferWithPairTables020dab68(struct Pair020dab68* obj, int p1, int p2) {
    int x = func_02057924();
    int a = obj->a;
    int b = obj->b;
    if (x && a && b) {
        RestorePairTables0207df90((char*)b);
        func_02057e6c(x, 0x16, a, p1, p2, b);
        BackupPairTables0207dfac((char*)b);
        return 1;
    }
    return 0;
}
