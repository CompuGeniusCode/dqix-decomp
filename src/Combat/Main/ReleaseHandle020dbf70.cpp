#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Obj020dbf70 {
    char pad[0xc];
    volatile int word_c;
    int word_10;
};

// USA: func_020dbf70
ARM void ReleaseHandle020dbf70(struct Obj020dbf70* o) {
    if (o->word_c < 0) return;
    ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->RemoveTask((int)(o->word_c));
    o->word_c = -1;
    o->word_10 = 0;
}
