#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

extern SignedAllocatorList data_0210f3d8;
extern SignedAllocatorList data_0210f3cc;

struct Obj020bc79c {
    void* backLink;                  /* 0x0 */
    SignedAllocatorList* ownerList;  /* 0x4 */
    void* peer;                      /* 0x8 */
    char pad[0x2c - 0xc];
    unsigned char flag0x2c;          /* 0x2c */
};

// USA: func_020bc79c  (semantic: ReleaseAndRelinkAllocator020bc79c)
extern "C" ARM void func_020bc79c(struct Obj020bc79c* obj) {
    if (obj->backLink != NULL) {
        *(void**)obj->backLink = NULL;
        obj->backLink = NULL;
    }
    SignedAllocatorList* owner = obj->ownerList;
    owner->Remove((SignedAllocatorHeader*)obj);
    obj->ownerList = NULL;
    if (obj->peer != NULL) {
        ((SignedAllocatorList*)((char*)owner + 0xc))->InsertAtEnd((SignedAllocatorHeader*)obj->peer);
        *(void**)((char*)obj->peer + 0xc) = NULL;
        obj->peer = NULL;
    }
    data_0210f3d8.Remove((SignedAllocatorHeader*)obj);
    data_0210f3cc.InsertAtEnd((SignedAllocatorHeader*)obj);
    obj->flag0x2c = 0;
}
