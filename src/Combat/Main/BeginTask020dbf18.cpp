#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Obj020dbf70;
void ReleaseHandle020dbf70(struct Obj020dbf70* o);

struct BattleTask020dbf18 {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
};

// USA: func_020dbf18
ARM int BeginTask020dbf18(struct BattleTask020dbf18* a, int b, int c, int d, int e) {
    int handle = (int)BackgroundLoader::GetInstance();
    ReleaseHandle020dbf70((struct Obj020dbf70*)a);
    a->f0 = c;
    a->f4 = d;
    a->f8 = e;
    a->fc = ((BackgroundLoader*)(handle))->QueueLoadFile((const char*)(b), (SafeAllocator*)(0));
    a->f10 = 1;
    return 0;
}
