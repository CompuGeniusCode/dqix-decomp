#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Obj020363b4 {
    unsigned char pad[0xc];
    void* fieldc;
};

struct StreamState020345e0;

extern "C" void* func_020362e4(void* obj, SafeAllocator* alloc);
void InitStreamState020345e0(struct StreamState020345e0* self);
extern "C" void func_0203461c(void* self, SafeAllocator* alloc, void* header, int size);

// USA: func_020363b4
ARM void LoadStreamIntoSlot020363b4(struct Obj020363b4* obj, SafeAllocator* alloc, void* header, int size) {
    void* sub;
    if (alloc == NULL || header == NULL) return;
    if (obj->fieldc == NULL) obj->fieldc = func_020362e4(obj, alloc);
    sub = obj->fieldc;
    if (sub == NULL) return;
    InitStreamState020345e0((struct StreamState020345e0*)((char*)sub + 4));
    func_0203461c((char*)sub + 4, alloc, header, size);
}
