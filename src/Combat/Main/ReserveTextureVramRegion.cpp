#include <globaldefs.h>

extern "C" void func_020bb700(int* out);
extern "C" void func_020bb910(int* dst);
extern "C" int func_020bb588(unsigned int size, int a, int b);
extern "C" int func_020bb7cc(unsigned int size, int a, int b);

struct Buf0207de48 { unsigned int v[10]; };
struct Pair0207de48 { int v[2]; };
struct PairBackupCtx0207de48 {
    Buf0207de48 bufA;
    Buf0207de48 bufB;
    int checksumA;
    int adjA;
    Pair0207de48 globalPair;
    Pair0207de48 globalPairCopy;
    int checksumB;
    int adjB;
};

// Reserves a scene's texture VRAM and snapshots the cursors first, so RewindTextureVramReservation
// can hand the region back by copying it over the working one. Images go to func_020bb588, which
// carves the five pools in the table at 0x020f1f00 and refuses 0x7fff0 or more, the DS texture-image
// ceiling; the request is split into 0x20000 steps, one VRAM slot, and only the last block's pointer
// is kept. Palettes go to func_020bb7cc on the pair at data_0210cf88. A size is zeroed when its
// allocation failed, so +0x54 and +0x6c say what was reserved, not what was asked.
extern "C" ARM void ReserveTextureVramRegion(void* pObj, int a, int b) {
    struct PairBackupCtx0207de48* obj = (struct PairBackupCtx0207de48*)pObj;
    func_020bb700((int*)&obj->bufA);
    obj->bufB = obj->bufA;
    func_020bb910(obj->globalPair.v);
    int remaining = a;
    obj->globalPairCopy = obj->globalPair;
    obj->checksumA = 0;

    while (remaining > 0) {
        if (remaining > 0x20000) {
            obj->checksumA = func_020bb588(0x20000, 0, 0);
            remaining -= 0x20000;
        } else {
            obj->checksumA = func_020bb588(remaining, 0, 0);
            remaining = 0;
        }
    }
    if (a != 0 && obj->checksumA == 0) a = 0;

    obj->checksumB = 0;
    if (b != 0) {
        obj->checksumB = func_020bb7cc(b, 0, 0);
    }
    if (b != 0 && obj->checksumB == 0) b = 0;

    obj->adjA = a;
    obj->adjB = b;
}
