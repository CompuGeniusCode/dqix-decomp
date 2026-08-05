#include <globaldefs.h>
#include "Memory/HMRFAllocator.h"

void ProcessCurrentContext020bdc60();
extern "C" int func_020bdc24(void* objPtr);

struct Obj020bd99c {
    HMRFAllocator* allocator;
    SignedAllocatorList list;
};

typedef void (*Callback020bd99c)(void*, int, int, int);

// USA: func_020bd99c
extern "C" ARM int func_020bd99c(struct Obj020bd99c* obj) {
    SignedAllocatorList* childList;
    int anyInvoked = 0;
    childList = (SignedAllocatorList*)obj->list.ElementBefore(NULL);
    if (childList != NULL) {
        do {
            SignedAllocatorHeader* entry = childList->ElementBefore(NULL);
            if (entry != NULL) {
                do {
                    Callback020bd99c cb = *(Callback020bd99c*)((char*)entry + 0xc);
                    if (cb != NULL) {
                        cb((char*)entry + 0x20, *(int*)((char*)entry + 8), *(int*)((char*)entry + 0x10), *(int*)((char*)entry + 0x14));
                        anyInvoked = 1;
                    }
                    entry = childList->ElementBefore(entry);
                } while (entry != NULL);
            }
            obj->list.Remove((SignedAllocatorHeader*)childList);
            childList = (SignedAllocatorList*)obj->list.ElementBefore(NULL);
        } while (childList != NULL);
    }
    obj->allocator->Free(3);
    if (anyInvoked) {
        ProcessCurrentContext020bdc60();
    }
    return func_020bdc24(obj);
}
