#include <globaldefs.h>

extern "C" void* func_020c8074(void *node);
struct RefNode020c80f8;
extern "C" void ReleaseNodeRef020c80f8(struct RefNode020c80f8 *node);

extern void* data_ov031_0224e60c;

// USA: func_ov031_0221a1d4
ARM void StoreAndRelease_0221a1d4(int value) {
    func_020c8074((char*)data_ov031_0224e60c + 0x1dc + 0x1000);
    *(int*)((char*)data_ov031_0224e60c + 0x1000) = value;
    ReleaseNodeRef020c80f8((struct RefNode020c80f8*)((char*)data_ov031_0224e60c + 0x1dc + 0x1000));
}
