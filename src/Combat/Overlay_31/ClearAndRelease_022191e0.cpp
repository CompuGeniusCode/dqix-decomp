#include <globaldefs.h>

extern "C" void* func_020c8074(void *node);
struct RefNode020c80f8;
extern "C" void ReleaseNodeRef020c80f8(struct RefNode020c80f8 *node);

extern void* data_ov031_0224e60c;

// USA: func_ov031_022191e0
ARM int ClearAndRelease_022191e0(void) {
    func_020c8074((char*)data_ov031_0224e60c + 0x1dc + 0x1000);
    int result = *(int*)((char*)data_ov031_0224e60c + 0x1000);
    ReleaseNodeRef020c80f8((struct RefNode020c80f8*)((char*)data_ov031_0224e60c + 0x1dc + 0x1000));
    return result;
}
