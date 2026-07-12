#include <globaldefs.h>
#include "System/Memory.h"

void* TryAcquireLock021142e8(void);
void CleanDataCacheRange(int addr, int size);
extern "C" int func_020cae94(int a, void* p, int c);
extern "C" int func_020c7e0c(void* a, void* p, int c);

extern int data_021142e8;

// USA: func_020d4168
ARM int CommitBattleContextBuffer020d4168(void* a, unsigned int b) {
    void* res = TryAcquireLock021142e8();
    if (res == NULL) {
        return 8;
    }
    VectorizedInvertedMemcpy(a, res, b);
    CleanDataCacheRange((int)res, b);
    int r = func_020cae94(0xa, res, 0);
    func_020c7e0c(&data_021142e8, res, 1);
    return (r < 0) ? 8 : 2;
}
