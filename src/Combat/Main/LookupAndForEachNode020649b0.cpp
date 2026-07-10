#include <globaldefs.h>

struct Node02064530;
struct Obj020649b0 { char pad0[0xc]; void* nodeHead; };

extern "C" struct Obj020649b0* func_02064490(void*, int, void*);
int ForEachNodeAllMatch02064530(void* a, struct Node02064530* node, void* c);

// USA: func_020649b0
ARM int LookupAndForEachNode020649b0(void* a, int mode, void* c) {
    struct Obj020649b0* r = func_02064490(a, mode, c);
    if (r == NULL) return 0;
    *(int*)((char*)c + 0x30) = 0;
    return ForEachNodeAllMatch02064530(a, (struct Node02064530*)r->nodeHead, c) != 0;
}
