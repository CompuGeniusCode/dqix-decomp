#include <globaldefs.h>
class AllocatorUnion;
int TailForward02012da4(AllocatorUnion*, void*);

extern int data_02114e20;

// USA: func_020998ac
ARM int ForwardFirstWord020998ac(int* p) {
    return TailForward02012da4((AllocatorUnion*)(&data_02114e20), (void*)(*p));
}
